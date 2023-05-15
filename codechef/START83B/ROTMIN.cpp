

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
	int n, p, q;
	cin >> n >> q >> p;
	string s;
	cin >> s;
	string ans = "";


	multiset<int> op1, op2;


	for(int i = 0; i < n; i++){
		// debug(p, q);
		int ch = s[i] - 'a';
		int pop = ch;
		int qop = 26 - ch;

		if(p >= pop){
			ans += 'a';
			p -= pop;
			op1.insert(pop);
		}
		else if(q >= qop){
			ans += 'a';
			q -= qop;
			op2.insert(qop);
		}
		else{
			if(p == 0 && q == 0){
				ans += s[i];
				continue;
			}

			if(q != 0){
				while(q > 0 && p < pop && !op1.empty()){
					auto it = --op1.end();
					int req = 26 - *it;
					if(req > q){
						break;
					}
					else{
						q -= req;
						op2.insert(req);
						p += *it;
						op1.erase(it);
					}
				}
			}

			if(p >= pop){
				ans += 'a';
				p -= pop;
				op1.insert(pop);
			}
			else{
				ans += (char)('a' + ch - p);
				p = 0;
			}
		}
	}

	cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}	