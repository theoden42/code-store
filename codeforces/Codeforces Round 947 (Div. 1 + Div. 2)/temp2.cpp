#include <bits/stdc++.h>
#include <debug.h>
using namespace std;

#define int long long

int32_t main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + m + 1);
	int cc = 0;
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		cc += k;
		for(int j = 0; j < k; j++){
			int val;
			cin >> val;
			val += n;
			adj[i].push_back(val);
			adj[val].push_back(i);
		}
	}

	int count = 0;
	vector<int> vis(n + m + 1);

	function<void(int)> dfs = [&](int source){
		vis[source] = 1;
		for(auto x: adj[source]) if(!vis[x])
			dfs(x);
	};

	for(int i = 1; i <= n + m; i++){
		if(!vis[i]){
			count += 1;
			dfs(i);
		}
	}

	if(cc == 0){
		cout << n << "\n";
	} else {
		cout << count - 1 << "\n";
	}

}