

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

#define int long long
#define size_t long long

void solve() {
	int n, h, w;
	cin >> n >> h >> w;
	vector<pair<int,int>> vp(n);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		vp[i] = {x, y};
	}

	sort(all(vp));

	do {
		for(int i = 0; i < (1ll << n); i++){
			set<pair<int,int>> st;
			for(int i = 0; i < h; i++){
				for(int j = 0; j < w; j++){
					st.insert({i, j});
				}
			}

			int flag = 1;
			for(int j = 0; j < n && !st.empty() && flag; j++){
				auto [sx, sy] = *(st.begin());
				auto [a, b] = vp[j];
				if(i >> j & 1)
					swap(a, b);

				if(sx + a > h || sy + b > w){
					flag = 0;
					break;
				}

				for(int k = sx; k < sx + a && flag; k++){
					for(int l = sy; l < sy + b && flag; l++){
						if(st.find({k, l}) == st.end()){
							flag = 0;
							break;
						} else {
							st.erase({k, l});
						}
					}
				}
			}

			if(flag && st.empty()){
				cout << "Yes\n";
				return;
			}
		}
	} while(next_permutation(all(vp)));


	cout << "No\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}