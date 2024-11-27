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
using ll =  __uint128_t;

using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#define int long long


// vector<vector<int>> pk(MAX_N, vector<int>(21, -1));	

// void preprocess(){
// 	for(int i = 2; i < MAX_N; i++){
// 		pk[i][0] = 1;
// 		int val = 1;
// 		for(int j = 1; j <= 20; j++){
// 			val = (val * i);

// 			if(val > MAX_N)
// 				break;

// 			pk[i][j] = val;	
// 		}
// 	}
// }


ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a);
        }
        a = (a * a);
        b = b >> 1; 
    }
    return (ans);
}

void solve() {
	int n;
	cin >> n;

	for(int i = 3; i <= 64; i++){
		int low = 2;
		int high = (1 << (int)ceil(1.0 * log2(1e18 + 5) / i));

		while(low <= high){
			ll mid = (low + high) / 2;

			ll num = (binpow(mid, i) - 1) / (mid - 1);

			if(num == n){
				cout << "YES\n";
				return;
			}
			else if(num < n){
				low = mid + 1;
			}
			else{
				high = mid - 1;
			}
		}
	}
	cout << "NO\n";

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