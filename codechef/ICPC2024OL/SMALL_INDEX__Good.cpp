

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
	vector<vector<int>> a(n + 1, vector<int>(2, 0));
	for(int i = 0; i < n; i++)
		cin >> a[i][0];
	for(int i = 0; i < n; i++)
		cin >> a[i][1];

	int dp[n + 1][100][100];
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 100; j++){
			for(int k = 0; k < 100; k++){
				dp[i][j][k] = -1e9;
			}
		}
	}

	auto change = [&](int m1, int m2, int c){
		if(c > m1){
			m2 = m1;
			m1 = c;
		} else if(c > m2){
			m2 = c;
		}
		return make_pair(m1, m2);
	};

	int t1 = max(a[0][0], a[0][1]);
	int t2 = max(a[1][0], a[1][1]);
	dp[2][max(t1, t2)][min(t1, t2)] = 0;
	for(int i = 2; i < n; i++){
		for(int mx1 = 0; mx1 < 100; mx1++){
			for(int mx2 = 0; mx2 < 100; mx2++) if(dp[i][mx1][mx2] != -1e9){
				for(int j = 0; j < 2; j++){
					auto [p1, p2] = change(mx1, mx2, a[i + 1][j]);
					int s = mx1 + mx2;
					if(a[i + 1][j] > s){
						dp[i + 1][p1][p2] = max(dp[i + 1][p1][p2], dp[i][mx1][mx2]);
					} else {
						// debug(s, mx1, mx2, a[i + 1][j]);
						dp[i + 1][p1][p2] = max(dp[i + 1][p1][p2], dp[i][mx1][mx2] + 1);
					}
				}
			}
		}
	}	



	int mn = 0;
	for(int j = 0; j < 100; j++){
		for(int k = 0; k < 100; k++){
			mn = max(mn, dp[n][j][k]);
		}
	}
	cout << mn << "\n";
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