
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
	int n;
	cin >> n;	
	vector<int> ele(n + 1, 0);
	for(int i = 1; i < n; i++){
		cin >> ele[i];
	}
	long long dp[n][n][n];
	for(int i = n; i >= 1; i--){
		for(int j = n; j >= 1; j--){
			for(int k = n; k >= 1; k--){
				if(k % 2 == 0){
					dp[k][i][j] = 
				}
			}
		}
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