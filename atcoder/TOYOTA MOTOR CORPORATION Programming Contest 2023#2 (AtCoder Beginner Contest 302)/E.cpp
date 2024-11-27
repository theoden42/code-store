

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
	int n, q;
	cin >> n >> q;

	vector<set<int>> adj(n + 1);

	set<int> number;
	for(int i = 1; i <= n; i++){
		number.insert(i);
	}

	for(int i = 1; i <= q; i++){
		int t;
		cin >> t;
		if(t == 1){
			int u, v;
			cin >> u >> v;
			adj[u].insert(v);
			adj[v].insert(u);

			if(number.find(u) != number.end()){
				number.erase(u);
			}
			if(number.find(v) != number.end()){
				number.erase(v);
			}
		}
		else{
			int v;
			cin >> v;
			for(auto x: adj[v]){
				adj[x].erase(v);
				if(adj[x].empty()){
					number.insert(x);
				}
			}
			adj[v].clear();	
			number.insert(v);
		}

		cout << number.size() << "\n";
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