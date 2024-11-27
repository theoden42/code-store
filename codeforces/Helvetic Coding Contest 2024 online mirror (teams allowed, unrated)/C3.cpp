

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
	int n, t;
    cin >> n >> t; 
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    vector<int> winner(n + 1);
    function<int(int,int)> dfs = [&](int source, int parent=-1){
    	int x = 0;
    	for(auto c: adj[source]) if(c != parent){
    		x |= dfs(c, source);
    	}
    	return winner[source] = (1 - x);
    };
	dfs(1, -1);

    vector<int> root(n + 1);
    vector<int> ans(n + 1);

    function<void(int,int)> reroot = [&](int source, int parent){
        int x = 0;
        for(auto c: adj[source]) if (c != parent){
            x += winner[c];
        }
        if(parent != -1){
            x += 1 - ((root[parent] - winner[source]) > 0);
        }
        root[source] = x;
        ans[source] = 1 - (root[source] > 0);
        for(auto c: adj[source]) if(c != parent){
            reroot(c, source);
        }
    };
    reroot(1, -1);

    vector<int> s(t);
    for(int i = 0; i < t; i++)
        cin >> s[i];

    for(int i = 0; i < t; i++){
        if(ans[s[i]] == 0){
            cout << "Ron\n";
        } else {
            cout << "Hermione\n";
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