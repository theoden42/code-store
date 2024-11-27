

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
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}

	function<int(int, int, map<int,int>&)> dfs = 
	[&](int source, int parent, map<int,int>& mp)->int{

		int count = 0;
		for(auto x: adj[source]){
			if(x == parent)continue;
			int val = dfs(x, source, mp);
			if(val == -1)return -1;
			if(val == 2 && mp[source])return -1;

			count += val;	
		}
		if(count > 2)return -1;

		if(count == 0 && mp[source])return 1;
		else return count;
	};

	int q;
	cin >> q;
	for(int i = 1; i <= q; i++){

		int k;
		cin >> k;
		map<int,int> mp;
		for(int i = 1; i <= k; i++){
			int pk;
			cin >> pk;	
			mp[pk] = 1;
		}

		auto ans = dfs(1, -1, mp);	

		if(ans == 0 || ans == 1 || ans == 2){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}