
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define int long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e12;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < m; i++){
    	int a, b, c;

    	cin >> a >> b >> c;
    	a--;
    	b--;
    	g[a].push_back({b, c});
    	g[b].push_back({a, c});
    }

    vector<int> dis(n, INF);
    vector<int> parent(n, -1);
    vector<int> vis(n, 0);
    multiset<pair<int,int>> mst;

    for(int i = 1; i < n; i++){
    	mst.insert({dis[i], i});
    }
    dis[0] = 0;
    mst.insert({dis[0], 0});

    debug(dis);
    debug(g);

    ll cost = 0;

    while(!mst.empty()){
    	auto it = mst.begin();
    	vis[it->second] = 1;

		int xx = it->second;
		int y = it->first;

		mst.erase(it);
		debug(xx, y);
		debug(g[xx]);

		for(auto& x: g[xx]){
			if(vis[x.first])continue;
			int a = x.first;
			int b = x.second;
			if(b < dis[a]){
				mst.erase(mst.find({dis[a], a}));
				dis[a] = b;
				mst.insert({dis[a], a});
			}
		}
    }
    debug(dis);

    for(int i = 0; i < n; i++){
    	if(dis[i] == INF){
    		cout << "IMPOSSIBLE\n";
    		return;
    	}
    	cost += dis[i];
    }
    cout << cost << "\n";

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