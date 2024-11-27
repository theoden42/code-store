

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
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}

	vector<vector<int>> adj(n);
	map<int, vector<int>> mp;
	for(int i = 0; i < n; i++){
		mp[a[i]].push_back(i);
		mp[b[i]].push_back(i);
	}

	for(auto it: mp){
		if(it.second.size() > 2){
			cout << "-1\n";
			return;
		}
		for(int k = 0; k < it.second.size(); k++){
			for(int l = k + 1; l < it.second.size(); l++){
				int u = it.second[k];
				int v = it.second[l];
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
	}


	vector<int> vis(n);

	function<int(int, int)> dfs 
	= [&](int ind, int flip){
		if(vis[ind])
			return 0;

		vis[ind] = 1;
		int count = flip;
		for(auto x: adj[ind]){
			if(!vis[x]){
				if(a[x] == a[ind] || b[x] == b[ind]){
					count += dfs(x, (flip + 1) % 2);
				}else{
					count += dfs(x, flip);
				}
			}
		}
		return count;
	};

	function<void(int ind, vector<int>&)> get_comp = 
	[&](int ind, vector<int>& comp){
		if(vis[ind])
			return;
		vis[ind] = 1;
		comp.push_back(ind);
		for(auto x: adj[ind]){
			if(vis[x])
				continue;
			get_comp(x, comp);
		}
	};

	function<void(vector<int>&)> resetvis = 
	[&](vector<int>& comp){
		for(auto ind: comp){
			vis[ind] = 0;
		}
	};


	int mxcount = 0;
	for(int i = 0; i < n; i++){
		if(vis[i])
			continue;


		vector<int> comp;
		get_comp(i, comp);
		resetvis(comp);
		int c1 = dfs(i, 0);
		resetvis(comp);
		int c2 = dfs(i, 1);

		mxcount += min(c1, c2);
	}

	cout << mxcount << "\n";


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