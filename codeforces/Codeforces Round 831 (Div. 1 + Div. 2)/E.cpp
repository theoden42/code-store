

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

    vector<vector<int>> adj;
    vector<int> heights;
    vector<int> childs;
    vector<int> parent;
    vector<int> assign;

    int dfs(int source, int parent){
        heights[source] = 1;
        for(auto x: adj[source]){
            if(x == parent)continue;
            heights[source]  = max(heights[source], dfs(x, source) + 1);
        }
        return heights[source];
    }

    int dp(int source, int parent){
        int x = heights[source];
        int sum = 0;
        for(auto x: adj[source]){
            if(x == parent)continue;
            sum += dp(x, source);
        }

        return max(sum, x);
    }

    void solve() {
        int n;
        cin >> n;
        adj.resize(n + 1);
        heights.resize(n + 1, 0);

        for(int i = 2; i <= n; i++){
        	int x;
        	cin >> x;
        	adj[x].push_back(i);
        	adj[i].push_back(x);
        } 
        dfs(1, -1);

        debug(heights);
        int ans = dp(1, -1);

        cout << ans << "\n";
    }


    int32_t main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int tc = 1;
        //cin >> tc;
        for (int t = 1; t <= tc; t++) {
            // cout << "Case #" << t << ": ";
            solve();
        }
    }