

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


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
	int n;	
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];

	int t1, t2;
	cin >> t1 >> t2;

	vector<vector<int>> adj(n);
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);	
		adj[v].push_back(u);
	}	

	vector<int> order;
	function<void(int, int)> inorder = [&](int src, int parent){
		vector<int> childs;
		for(auto x: adj[src]){
			if(x != parent){
				childs.push_back(x);
			}
		}
		if(childs.size() > 0)
			inorder(childs[0], src);
		order.push_back(src);
		if(childs.size() > 1)
			inorder(childs[1], src);
	};
	inorder(0, -1);
	debug(order);

	int m;
	cin >> m;
	cout << v[order[m - 1]] << "\n";
}