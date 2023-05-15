

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
		string x;
		cin >> x;

		vector<vector<int>> count(n + 1, vector<int>(10, 0));
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= 9; j++){
				count[i][j] = count[i - 1][j];
			}
			int val = x[i - 1] - '0';
			count[i][val]++;
		}


		ll ans = 0;

		for(int i = 0; i < n; i++){
			for(int j = 1; j <= 100; j++){
				int x = i + j;

				if(x > n)break;

				vector<int> check(10, 0);
				for(int k = 0; k < 10; k++){
					check[k] = count[x][k] - count[i][k];
				}


				int cn = 0;
				for(int k = 0; k < 10; k++){
					if(check[k] != 0)cn++;
				}


				int f = 1;

				for(int i = 0; i < 10; i++){
					if(check[i] > cn)f = 0;
				}
				if(f)ans++;
			}
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