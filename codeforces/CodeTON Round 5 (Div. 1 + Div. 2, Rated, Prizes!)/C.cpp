

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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    vector<int> dp(n + 1, 0);

    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++){
    	mp[a[i]].push_back(i);
    }

    dp[n] = 0;
    for(int i = n - 1; i >= 0; i--){
		dp[i] = dp[i + 1];	

		auto it = upper_bound(all(mp[a[i]]), i);
		if(it != mp[a[i]].end()){
			int ind = *it;
			int val;
			if(dp[ind] == dp[ind + 1]){
				val = ind - i + 1;
			}
			else{
				val = ind - i;	
			}

			dp[i] = max(dp[i], dp[ind] + val);
		}
    }

    cout << dp[0] << "\n";
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