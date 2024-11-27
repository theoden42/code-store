

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

void djikstra(int n, int src, vector<vector<pair<int,int>>>& adj, vector<int>& dis){
	if(src != -1){
		dis[src] = 0;
	}
	multiset<pair<int,int>> mst;
	for(int i = 1; i <= n; i++){
		mst.insert({dis[i], i});
	}
	while(!mst.empty()){
		// debug(mst);
		auto [d, i] = *mst.begin();
		mst.erase(mst.begin());
		for(auto [x, w]  : adj[i]){
			if(dis[x] > d + w){
				mst.erase({dis[x], x});
				dis[x] = d + w;
				mst.insert({dis[x], x});
			}
		}
	}
}

void solve() {
    int n, m;
    cin >> n >> m;
    int t0, t1, t2;
    cin >> t0 >> t1 >> t2;
    vector<vector<pair<int,int>>> adj1(n + 1), adj2(n + 1);
    for(int i = 0; i < m; i++){
    	int u, v, l1, l2;
    	cin >> u >> v >> l1 >> l2;
    	adj1[u].push_back({v, l1});
    	adj1[v].push_back({u, l1});
    	adj2[u].push_back({v, l2});
    	adj2[v].push_back({u, l2});
    }

    vector<int> dis1(n + 1, 1e18), dis2(n + 1, 1e18);
    djikstra(n, 1, adj1, dis1);
    djikstra(n, n, adj1, dis2);

    // debug(dis1, dis2);

    auto check = [&](int mid){
    	vector<int> dis3(n + 1, 1e18);
    	int th = max(0ll, t1 - mid);
        // debug(mid, th);
    	for(int i = 1; i <= n; i++){
    		if(dis1[i] <= th){
    			dis3[i] = dis1[i];
    		}
    	}
    	djikstra(n, -1, adj2, dis3);
        // debug(dis3);
    	for(int j = 1; j <= n; j++){
    		int time = max(t2, mid + dis3[j]) + dis2[j];
    		if(time <= t0){
                // debug(j, time);
    			return true;
    		}
    	}
    	return false;
    };

    int lb = 0;
    int ub = t0;
    int ans = -1;
    while(lb <= ub){
    	int mid = (lb + ub) / 2;
    	if(check(mid)){
    		ans = mid;
    		lb = mid + 1;
    	} else {
    		ub = mid - 1;
    	}
    }

    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}