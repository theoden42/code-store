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
const ll MOD = 1e18 + 7;
const ll INF = 1e18;

#define int long long

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

int dp[200200][5][2];

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> arr;	

	arr.push_back(1);

	for(int i = 1; i < 5; i++){
		int x = arr.back() * 10;
		arr.push_back(x);
	}
	// debug(arr);

	reverse(all(s));

	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 5; j++){
			for(int f = 0; f < 2; f++){
				dp[i][j][f] = -INF;
			}
		}
	}

	dp[0][0][0] = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5; j++){
			for(int f = 0; f < 2; f++){
				if(dp[i][j][f] != -INF){
					int ch = s[i] - 'A';
					for(int x = 0; x < 5; x++){

						if(x != ch && f == 1)continue;

						int w = dp[i][j][f];
						if(x >= j){
							w += arr[x];
						}
						else{
							w -= arr[x];
						}
						dp[i + 1][max(x, j)][f + (x != ch)] = max(dp[i + 1][max(x, j)][f + (x != ch)], w);
					}
				}

			}
		}
	}


	int ans = -INF;

	for(int j = 0; j < 5; j++){
		for(int k = 0; k < 2; k++){
			ans = max(ans, dp[n][j][k]);
			// debug(dp[n][j][k]);
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