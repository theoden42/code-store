

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

	int mn = n;

	auto check = [&](int l){
		int f = 1;
		for(int i = 0; i < l; i++){
			vector<int> freq(26);
			int j = i;
			while(j < n){
				freq[s[j] - 'a'] += 1;
				j += l;
			}

			sort(all(freq));
			if(freq[24] == 0)
				continue;
			else if(freq[24] == 1 && freq[23] == 0){
				if(!f)
					return 0;
				else {
					f = 0;
					continue;
				}
			} else {
				return 0;
			}
		}

		return 1;
	};

	for(int i = 1; i * i <= n; i++) if(n % i == 0){
		int f1 = i;
		int f2 = n / i;
		if(check(f1))
			mn = min(mn, f1);
		if(check(f2))
			mn = min(mn, f2);
	}


	cout << mn << "\n";
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