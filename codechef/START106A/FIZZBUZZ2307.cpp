

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
    vector<int> indeg(n + 1);
    for(int i = 1; i <= n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	indeg[v] += 1;
    }
    int root = 1;
    for(int i = 1; i <= n; i++){
    	if(indeg[i] == 0){
    		root = i;
    		break;
    	}
    }

    vector<int> depth(n + 1);
    vector<int> size(n + 1);

    function<int(int, int)> dfs = [&](int source, int dis){
    	int sum = 1;
    	depth[source] = dis;
    	for(auto x: adj[source]){
    		sum += dfs(x, dis + 1);
    	}
    	size[source] = sum;
    	return sum;
    };
    dfs(root, 1);

    vector<int> diff(n + 2);
    for(int i = 1; i <= n; i++){
    	int lb = depth[i];
    	int rb = n - size[i] + 1;
    	debug(i, lb, rb);
    	diff[lb] += 1;
    	diff[rb + 1] -= 1;
    }

    for(int i = 1; i <= n; i++){
    	diff[i] = diff[i - 1] + diff[i];
    }

    for(int i = 1; i <= n; i++){
    	cout << diff[i] << " ";
    }
    cout << "\n";
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