

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

#define int long long

void solve() {
   int n;
   cin >> n;
   vector<int> a(n + 1);
   for(int i = 1; i <= n; i++){
   	cin >> a[i];
   }
   vector<vector<int>> adj(n + 1);
   vector<int> parent(n + 1);
   for(int i = 0; i < n - 1; i++){
   	int p;
   	cin >> p;
   	adj[i + 2].push_back(p);
   	adj[p].push_back(i + 2);
   	parent[i + 2] = p;
   }
   vector<int> childsum(n + 1);
   function<void(int,int)> dfs = [&](int src, int pnt){
   	int sum = 0;
   	for(auto x: adj[src]) if(x != pnt) {
   		childsum[src] += a[x];
   		dfs(x, src);
   	}
   	if(adj[src].size() == 1 && src != 1){
   		childsum[src] = 1e18;
   	}
   }; dfs(1, -1);

   int ans = 0;
   function<void(int,int)> fix = [&](int src, int pnt){
   	for(auto x: adj[src]) if(x != pnt){
   		fix(x, src);
   	}
   	int left = a[src] - childsum[src];
   	queue<pair<int,int>> q;
   	for(auto x: adj[src]) if(x != pnt){
   		q.push({x, 1});
   	}
   	while(left > 0 && !q.empty()){
   		auto [ind, lev] = q.front();
   		q.pop();
   		int dif = max(0ll, childsum[ind] - a[ind]);
   		int add = min(dif, left);
   		a[ind] += add;
   		left -= add;
   		ans += lev * add;
   		for(auto x: adj[ind]) if(x != parent[ind]){
   			q.push({x, lev + 1});
   		}
   	}
   }; fix(1, -1);

   cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}