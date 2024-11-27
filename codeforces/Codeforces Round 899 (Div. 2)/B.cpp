

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
	vector<vector<int>> s(n);
	map<int, set<int>> mp;

	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			int x;
			cin >> x;
			s[i].push_back(x);
			mp[x].insert(i);
		}
	}
	int ans = 0;
	for(auto& [val, st]: mp){
		set<int> nw;
		for(int i = 0; i < n; i++){
			if(st.find(i) == st.end()){
				for(auto e: s[i]){
					nw.insert(e);
				}
			}
		}
		ans = max(ans, (int)nw.size());
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