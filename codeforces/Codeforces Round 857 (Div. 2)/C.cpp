/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define int long long 
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


bool check(vector<vector<int>>& a){
	int n = a.size();
	int m = a[0].size();
	int flag = 0;
	for(int i = 0; i < n - 3; i++){
		for(int j =	0; j < n - 3; j++){
			int a1 = (a[i][j] ^ a[i][j + 1] ^ a[i + 1][j] ^ a[i + 1][j + 1]);
			int a2 = (a[i + 2][j + 2] ^ a[i + 2][j + 3] ^ a[i + 3][j + 2] ^ a[i + 3][j + 3]); 
			int a3 = (a[i][j + 2] ^ a[i][j + 3] ^ a[i + 1][j + 2] ^ a[i + 1][j + 3]);
			int a4 = (a[i + 2][j] ^ a[i + 2][j + 1] ^ a[i + 3][j] ^ a[i + 3][j + 1]);
			if(a1 != a2 || a3 != a4){
				cout << i << " " << j << "\n";
				debug(a1, a2, a3, a4);
				return false;
			}
		}
	}
	return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    int k = 0;

    for(int i = 1; i <= n; i += 1){
    	for(int j = 1; j <= m; j += 1){
    		ans[i - 1][j - 1] = (i << 10) + j;
    	}
    }

    cout << n * m << "\n";
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; j++){
    		cout << ans[i][j] << " ";
    	}
    	cout << "\n";
    }



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