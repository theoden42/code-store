

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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// #define int long long


void solve() {
    int n;
    cin >> n;

    int m = sqrt(2 * n) + 5;

    vector<vector<int>> mp(m + 2, vector<int>(n + 1, 0));


    vector<int> a(n);
    vector<int> b(n);


    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }

    for(int i = 0; i < n; i++){
    	if(a[i] <= m){
    		mp[a[i]][b[i]] += 1;
    	}
    }


    ll ans = 0;
    for(int i = 0; i < n; i++){

    	int x = a[i];
    	if(x > m)continue;

    	ll left = x * x - b[i];	
    	if(left < 0 || left > n)continue;

    	if(left == b[i]){
    		ans += mp[x][left] - 1;
    	}
    	else{
    		ans += mp[x][left];
    	}
    }

    ans /= 2;

    for(int i = 0; i < n; i++){
    	int x = a[i];

    	for(int j = 1; j < x && j * j <= 2 * n && j * x <= 2 * n; j++){
    		int left = x * j - b[i];

    		if(left < 0 || left > n)continue;

    		ans += mp[j][left];
    	}
    }
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