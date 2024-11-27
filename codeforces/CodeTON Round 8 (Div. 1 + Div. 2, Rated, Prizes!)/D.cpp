

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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
    	for(int j = i; j < n; j++){
    		cin >> a[i][j];
    	}
    }

    vector<vector<int>> dp(n + 1);
    dp[n].push_back(0);

    for(int i = n - 1; i >= 0; i--){
    	multiset<vector<int>> mst;
    	vector<int> temp;

    	mst.insert({dp[i + 1].back(), i + 1, dp[i + 1].size() - 1});

    	for(int j = i; j < n; j++){
    		if(j + 2 >= n)
    			mst.insert({a[i][j], j + 2, -1});
    		else 
    			mst.insert({a[i][j] + dp[j + 2].back(), j + 2, dp[j + 2].size() - 1});
    	}


    	while(!mst.empty() && temp.size() < k){
    		auto v = *(--mst.end());
    		mst.erase(--mst.end());
    		temp.push_back(v[0]);

    		int nind = v[2] - 1;
    		int nj = v[1];

    		if(nind >= 0){
    			if(nj != i + 1)
    				mst.insert({a[i][nj - 2] + dp[nj][nind], nj, nind});
    			else 
    				mst.insert({dp[nj][nind], nj, nind});
    		}
    	}

    	reverse(all(temp));
    	dp[i].assign(all(temp));
    }


    sort(all(dp[0]));
    reverse(all(dp[0]));

    for(int i = 0; i < k; i++){
    	cout << dp[0][i] << " \n"[i == k - 1];
    }

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