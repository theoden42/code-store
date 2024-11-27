

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
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    vector<int> sum(n + 2);

    vector<vector<int>> op(n + 1);
    for(int i = 0; i < m; i++){
    	int l, r;
    	cin >> l >> r;
    	op[l].push_back(r);
    	sum[l] += 1;
    	sum[r + 1] -= 1;
    }


    vector<int> mx(n + 1);
    multiset<int> mst;
    for(int i = 1; i <= n; i++){
    	sum[i] += sum[i - 1];
    	for(auto x: op[i]){
    		mst.insert(x);
    	}	

    	if(mst.empty())
    		mx[i] = i;
    	else 
    		mx[i] = *(--mst.end());
    	while(!mst.empty() && *mst.begin() <= i){
    		mst.erase(mst.begin());
    	}
    }

    // debug(mx);

    vector<int> dp(n + 2);
    for(int i = n; i >= 0; i--){
    	dp[i] = dp[i + 1];
    	dp[i] = max(dp[i], dp[mx[i] + ] + sum[i]);
    }

    int ans = *max_element(all(dp));
    cout << ans << "\n";

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