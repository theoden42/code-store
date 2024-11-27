

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
const ll INF = 1e15;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v;
    int sum = 0;
    for(int i = 0; i < n; i++){
    	int x, y, z;
    	cin >> x >> y >> z;
    	v.push_back({x, y, z});
    	sum += z;
    }

    vector<int> dp(sum + 1, INF), ndp(sum + 1, INF);


    dp[0] = 0;
    for(int i = 0; i < n; i++){

    	for(int j = 0; j <= sum; j++){
    		ndp[j] = INF;
    	}

    	int cost = 0;
    	int tot = v[i][0] + v[i][1];
    	if(v[i][0] < (tot + 1) / 2){
    		cost = (tot + 1) / 2 - v[i][0];
    	}

    	for(int j = 0; j <= sum; j++){
    		if(j + v[i][2] <= sum)
    			ndp[j + v[i][2]] = min(ndp[j + v[i][2]], cost + dp[j]);

    		ndp[j] = min(ndp[j], dp[j]);
    	}
    	dp = ndp;
    }

    int mnans = 1e18;
    for(int i = (sum + 1) / 2; i <= sum; i++){
    	mnans = min(mnans, dp[i]);
    }
    cout << mnans << "\n";

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