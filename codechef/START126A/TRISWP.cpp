

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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int count = 0;
	int f = 0;

	for(int i = 0; i < n - 2; i++){
		string x = s.substr(i, 3);
		string y = "";
		y += x[1];
		y += x[2];
		y += x[0];

		if(y != x){
			count += 1;
			if(i < n - 3){
				if(s[i] == s[i + 1] && s[i] == s[i + 3])
					i += 1;  
			}
		}
		else if(!f){
			count += 1;
			f = 1;
		}


	}

	cout << max(1, count) << "\n";
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