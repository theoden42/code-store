

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
	vector<vector<vector<int>>> adj(n);
	for(int i = 0; i < m; i++){ 
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		a--;
		b--;
		adj[a].push_back({b, x, y});
		adj[b].push_back({a, -x, -y});
	}

	vector<pair<int,int>> cord(n, {1e18, 1e18});
	vector<int> vis(n);

	queue<int> q;
	cord[0] = {0, 0};
	q.push(0);
	vis[0] = 1;
	while(!q.empty()){
		auto pos = q.front();
		q.pop();
		for(auto x: adj[pos]){
			if(!vis[x[0]]){
				cord[x[0]].first = cord[pos].first + x[1];
				cord[x[0]].second = cord[pos].second + x[2];
				vis[x[0]] = 1;
				q.push(x[0]);
			}

		}
	}

	for(int i = 0; i < n; i++){
		if(cord[i].first == 1e18){
			cout << "undecidable\n";
		} else {
			cout << cord[i].first << " " << cord[i].second << "\n";
		}
	}
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