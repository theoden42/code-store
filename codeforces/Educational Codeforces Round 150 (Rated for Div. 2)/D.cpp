

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

int dp[2020][2020][2];

void solve() {

	int n;
	cin >> n;
	vector<pair<int,int>> a(n + 1, {-1, -1});

	for(int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
	}

	sort(all(a));

	debug(a);


	for(int i = 0; i <= n + 1; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; k < 2; k++){
				dp[i][j][k] = INF;
			}
		}
	}

	dp[1][0][1] = 0;

	auto check = [&](pair<int,int> a, pair<int,int> b){
		// intersectinng or not
		pair<int,int> x = min(a, b);
		pair<int,int> y = max(a, b);
		if(x.second < y.first){
			return false;
		}
		else{
			return true;
		}

	};

	auto get_bigger_ind = [&](int ind1, int ind2){
		if(a[ind1].second > a[ind2].second)return ind1;
		else return ind2;
	};

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			for(int k = 0; k < 2; k++){
				if(dp[i][j][k] == INF)continue;
				if(k){
					if(!check(a[i], a[j]))
						dp[i + 1][i][0] = min(dp[i + 1][i][0], dp[i][j][k]);

					dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][k] + 1);
				}else{
					if(check(a[i], a[j])){
						int nw = get_bigger_ind(j, i);
						dp[i + 1][nw][1] = min(dp[i + 1][nw][1], dp[i][j][k]);
					}
					dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + 1);
				}
			}
		}
	}

	// for(int i = 1; i <= n + 1; i++){
	// 	for(int j = 0; j < i; j++){
	// 		for(int k = 0; k < 2; k++){
	// 			debug(i, j, k, dp[i][j][k]);
	// 		}
	// 	}	
	// }

	int ans = n;
	for(int j = 0; j <= n; j++){
		ans = min(ans, dp[n + 1][j][1]);
	}

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