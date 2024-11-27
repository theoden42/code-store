

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


int f(int n, int k, int move){
	if(n == 0){
		return (move + 1) % 2;
	}
	if(dp[n][move] != -1)return dp[n][move];

	for(int x = 0; x <= 30; x++){
		if(pow(k, x) > n){
			break;
		}
		int rem = n - pow(k , x);
		if(f(rem, k, (move + 1) % 2, dp) == move){
			return dp[n][move] = move;
		}
	}

	return dp[n][move] = (move + 1) % 2;
}



void solve() {
	int n = rng() % 1001 + 1000;
	int k = rng() % 100;

	cout << n << " " << k << endl;

	vector<vector<int>> dp(n + 1, vector<int> (2, -1));

	int ans = f(n, k, 0, dp);

	if(ans == 0){
		cout << "Shivans\n";
	}
	else{
		cout << "Tina\n";
	}

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