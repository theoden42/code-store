

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
	vector<vector<int>> adj(n + m + 1);
	for(int i = 1; i <= n; i++){
		int sz;
		cin >> sz;
		for(int j = 1; j <= sz; j++){
			int x;
			cin >> x;
			int val = n + x;
			adj[i].push_back(val);
			adj[val].push_back(i);
		}
	} 

	vector<int> vis(n + m + 1, 0);
	vector<int> dis(n + m + 1, 1e9);


	queue<int> q;
	q.push(n + 1);
	dis[n + 1] = 0;
	vis[n + 1] = 1;

	while(!q.empty()){
		int val = q.front();
		q.pop();
		for(auto x: adj[val]){
			if(!vis[x]){
				dis[x] = min(dis[val] + 1, dis[x]);
				vis[x] = 1;
				q.push(x);
			}
		}
	}

	if(!vis[n + m]){
		cout << "-1\n";
	}
	else{
		int d = dis[n + m];

		int ans = d / 2 - 1;
		cout << ans << "\n";
	}


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