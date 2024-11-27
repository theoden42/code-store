

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
    
}


int main() {
    int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int m;
	cin >> m;
	vector<int> b(m);
	for(int j = 0; j < m; j++){
		cin >> b[j];
	}

	int p;
	cin >> p;
	vector<vector<vector<string>>> dp(n + 1, vector<vector<string>> (m + 1, vector<string>(p + 1, "-1")));
	for(int i = 0; i <= n; i++){
		dp[i][m][0] = "";
	}
	for(int j = 0; j <= m; j++){
		dp[n][j][0] = "";
	}


	for(int i = n - 1; i >= 0; i--){
		for(int j = m - 1; j >= 0; j--){
			for(int k = 0; k <= p; k++){
				vector<string> options;
				if(dp[i + 1][j][k] != "-1")
					options.push_back(dp[i + 1][j][k]);
				if(dp[i][j + 1][k] != "-1")
					options.push_back(dp[i][j + 1][k]);
				if(k > 0 && dp[i + 1][j][k - 1] != "-1")
					options.push_back(dp[i + 1][j][k - 1] + to_string(a[i]));
				if(k > 0 && dp[i][j + 1][k - 1] != "-1")
					options.push_back(dp[i][j + 1][k - 1] + to_string(b[j]));

				for(auto& o: options){
					reverse(all(o));
				}

				sort(all(options));

				debug(i, j, k);
				debug(options);

				if(!options.empty()){
					dp[i][j][k] = options.back();
					reverse(all(dp[i][j][k]));
				}
				debug(dp[i][j][k]);
			}
		}
	}

	reverse(all(dp[0][0][p]));

	for(auto c: dp[0][0][p]){
		cout << c << " ";
	}
	cout << "\n";
}