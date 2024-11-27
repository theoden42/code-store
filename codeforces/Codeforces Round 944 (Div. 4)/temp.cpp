
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

int main() {	
	int n, m;
	cin >> n >> m;

	unordered_map<string,int> mp;
	unordered_map<int,string> rev;

	int count = 0;
	vector<vector<string>> st(n, vector<string>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> st[i][j];
		}
	}

	set<string> temp;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			temp.insert(st[i][j]);
		}
	}

	for(auto s: temp){
		mp[s] = count;
		rev[count] = s;
		count++;
	}

	vector<vector<int>> adj(count);
	for(int i = 0; i < n; i++){
		adj[mp[st[i][0]]].push_back(mp[st[i][1]]);
	}

	vector<int> vis(count);
	vector<int> order;

	function<void(int)> dfs = [&](int v){
		order.push_back(v);
		vis[v] = 1;
		vector<int> child;
		for(auto x: adj[v]){
			child.push_back(x);
		}
		sort(all(child));
		for(auto c: child){
			dfs(c);
		}
	};

	dfs(mp["ABC"]);
	for(int i = 0; i < count; i++){
		if(!vis[i])
			dfs(i);
	}

	for(auto o: order){
		cout << rev[o] << " ";
	}
	cout << "\n";
}