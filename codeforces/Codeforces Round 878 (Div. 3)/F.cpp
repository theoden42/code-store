

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
const ll INF = 1e18;

#define int long long 

void solve() {
    int n, m;
    cin >> n >> m;
    int r;
    cin >> r;

    vector<vector<int>> shots(r + 1);
    shots[0] = {0, 0, 0};
    for(int i = 1; i <= r; i++){
    	int t, d, cord;
    	cin >> t >> d >> cord;
    	shots[i] = {t, d, cord};	
    }

    sort(all(shots));   


    bool dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = false;
        }
    }  
    dp[0][0] = 1;

    int p = 0;

    for(int t = 1; t <= n + m + r + 1; t++){
        for(int i = n; i >= 0; i--){
            for(int j = m; j >= 0; j--){
                if(dp[i][j]){
                    if(i < n)
                        dp[i + 1][j] = 1;
                    if(j < m)
                        dp[i][j + 1] = 1;
                }

            }
        }

        while(p <= r && shots[p][0] <= t){
            vector<int> s = shots[p];
            if(s[0] == t){  
                if(s[1] == 1){
                    int row = s[2];
                    for(int j = 0; j <= m; j++){
                        dp[row][j] = 0;
                    }
                }else{
                    int col = s[2];
                    for(int j = 0; j <= n; j++){
                        dp[j][col] = 0;
                    }
                }
            }
            p++;
        }

        if(dp[n][m]){
            cout << t << "\n";
            return;
        }
        int f = 1;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(dp[i][j]){
                    f = 0;
                    break;
                }
            }
        }
        if(f){
            cout << "-1\n";
            return;
        }
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