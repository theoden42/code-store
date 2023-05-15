
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll ans = 0;

void dfs(int source, int parent, int val, vector<vector<pair<int,int>>>& adj, map<int,int>& mp){

	vector<int> indexes;
	mp[val]++;

	for(auto& x: adj[source]){
		if(x.first == parent)continue;

		if(x.second == 0){
			indexes.push_back(x.first);
			continue;
		}
		else{
			dfs(x.first, source, val ^ x.second, adj, mp);
		}
	}

	for(auto& i: indexes){
		map<int,int> mp2;
		dfs(i, source, 0, adj, mp2);
		int mx = 0;
		for(auto& temp: mp2){
			mx = max(mx, temp.second);
		}
		ans += mx;
	}

}


void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < n - 1; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--;
    	v--;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }


    ans = 0;
    map<int,int> mp;
    dfs(0, -1, 0, adj, mp);
    ans += mp[0] - 1;


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