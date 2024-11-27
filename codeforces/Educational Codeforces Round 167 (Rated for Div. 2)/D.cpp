

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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(m);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < m; i++)
		cin >> c[i];
	map<int,vector<int>> mp;
	for(int i = 0; i < n; i++){
		mp[a[i]].push_back(i);
	}
	vector<int> best(1e6 + 5, 1e18);
	for(int i = 1; i <= 1e6; i++){
		if(mp.find(i) != mp.end()){
			vector<int> val;
			for(auto ind: mp[i]){
				int t = a[ind] - b[ind];
				val.push_back(t);
			}
			best[i] = best[i - 1];
			for(auto v: val){
				best[i] = min(best[i], v);
			}
		} else {
			best[i] = best[i - 1];
		}
	}
	// debug(best);
	vector<int> ans(1e6 + 5);
	for(int i = 1; i <= 1e6; i++){
		if(best[i] <= i){ 
			ans[i] = 2 + ans[i - best[i]];
		}
	}
	int fin = 0;
	for(int i = 0; i < m; i++){
		int x = c[i];
		if(x > 1e6){
			int l = best[1e6];
			int nb = (x - 1e6 + l - 1) / l;
			int nx = x - nb * l;
			fin += 2 * nb + ans[nx];
		} else{
			fin += ans[x];
		}
	}
	cout << fin << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}