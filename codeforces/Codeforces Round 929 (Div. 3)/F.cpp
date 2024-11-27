

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
    vector<vector<int>> g(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> g[i][j];
    	}
    }	

    vector<vector<int>> vis(n, vector<int>(m, 0)), dis(n, vector<int>(m, 1e18));
    queue<pair<int,int>> q;
    dis[0][0] = 0;
    q.push({0, 0});

    while(!q.empty()){
    	auto [i, j] = q.front();

    	q.pop();
    	if(g[(i + 1) % n][j] != 1 && g[(i + 2) % n][j] != 1 && !vis[(i + 2) % n][j]){
    		dis[(i + 2) % n][j] = 1 + dis[i][j];
    		vis[(i + 2) % n][j] = 1;
    		q.push({(i + 2) % n, j});
    	} 
    	if(j < m - 1 && !vis[(i + 1) % n][j + 1] && g[(i + 1) % n][j + 1] != 1){
    		dis[(i + 1) % n][j + 1] = dis[i][j] + 1;
    		vis[(i + 1) % n][j + 1] = 1;
    		q.push({(i + 1) % n, j + 1});
    	}
    }

    int mx = 1e18;
    for(int i = 0; i < n; i++){
    	if(dis[i][m - 1] == 1e18)
    		continue;

    	int nmx = dis[i][m - 1];
    	int ni = (i - nmx % n + n) % n;
    	nmx += (ni + 1) % n;
    	mx = min(nmx, mx);
    }

    cout << ((mx == 1e18) ? -1: mx) << "\n";
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