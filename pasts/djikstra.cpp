
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define int long long

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;

int n, m;
vector<pair<int,int>> g[MAX_N];
vector<int> dist(MAX_N, INF);
vector<bool> vis(MAX_N, false);
vector<int> par(MAX_N, -1);

void djikstra(int source){
	multiset<pair<int,int>> mp;
	mp.insert({0, source});
	dist[source] = 0;
	while(!mp.empty()){
		auto node = *mp.begin();
		int cur_v = node.second;
		mp.erase(node);
		if(vis[cur_v]){
			continue;
		}
		for(auto& x: g[cur_v]){
			if(dist[x.first] > dist[cur_v] + x.second){
				dist[x.first] = dist[cur_v] + x.second;
				par[x.first] = cur_v;
				mp.insert({dist[x.first], x.first});
			}
		}
	}
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    	int a, b, w;
    	cin >> a >> b >> w;
    	g[a].push_back({b, w});
    	g[b].push_back({a, w});
    }
    djikstra(1);
    vector<int> path;
    int x = n;
    while(x != -1){
    	path.push_back(x);
    	x = par[x];
    }
    // for(auto& y: par){
    // 	cout << y << " ";
    // }
    // cout << endl;
    if(path.size() == 1){
    	cout << -1 << "\n";
    	return;
    }
    for(int i = path.size() - 1; i >= 0; i--){
    	cout << path[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //;cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}