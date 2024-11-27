

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


vector<vector<int>> adj;
map<pair<int,int>, int> mp;
vector<int> ans;

int dfs(int source, int parent){

	int count = 1;
	for(auto& x: adj[source]){
		if(x != parent){
			int val = dfs(x, source);
			if(val == -1)return -1;
			count += val;
		}
	}

	if(count > 3){
		return -1;
	}
	if(count == 3){
		if(parent != -1){
			pair<int,int> p = {source, parent};
			int e = mp[p];
			ans.push_back(e);
		}
		return 0;
	}
	else{
		return count;
	}
}	

void solve() {
	int n;
	cin >> n;
	adj.clear();
	adj.resize(n);
	mp.clear();
	ans.clear();
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		mp[{u, v}] = i + 1;
		mp[{v, u}] = i + 1;
	}

	if(dfs(0, -1) == 0){
		cout << ans.size() << "\n";
		for(auto x: ans){
			cout << x << " ";
		}
		cout << "\n";
	}
	else{
		cout << "-1\n";
	}

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