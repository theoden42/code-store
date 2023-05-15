
    /* @uthor: (g)theoden42 */

    #include <bits/stdc++.h>
    using namespace std;

    #ifdef ON_PC
        #include <debug.h>
    #else
        #define debug(x...)
    #endif

    #define ll long long
    #define ld long double
    #define all(a) (a).begin(), (a).end()
    #define int long long

    const int MAX_N = 1e6 + 5;
    const ll MOD = 1e9 + 7;
    const ll INF = 1e9;

    vector<vector<vector<pair<int,int>>>> dp(3000 + 1, vector<vector<pair<int,int>>>(3000 + 1, vector<pair<int,int>>(2, {0, 0})));


    void solve() {
    	int n;
    	cin >> n;
    	vector<int> ele(n);
    	for(int i = 0; i < n; i++){
    		cin >> ele[i];
    	}

        // dp[n][n][0] = dp[n][n][1] = {0, 0}; 

        for(int i = 0; i < n; i++){
            for(int k = 0; k < 2; k++){
                if(k == 0)dp[i][i][k] = {ele[i], 0};
                else dp[i][i][k] = {0, ele[i]};
            }
        }



        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                for(int k = 0; k < 2; k++){ 

                    pair<int,int> p1 = dp[i][j - 1][(k + 1) % 2];
                    pair<int,int> p2 = dp[i + 1][j][(k + 1) % 2];

                    int x = ele[i];
                    int y = ele[j];

                    // debug(p1, p2, x, y);

                    if(k == 0){
                        int a = p2.first + x - p2.second;
                        int b = p1.first + y - p1.second;

                        if(a >= b){
                            dp[i][j][k] = {p2.first + x, p2.second};
                        }
                        else{
                            dp[i][j][k] = {p1.first + y, p1.second};
                        }
                    } 
                    else{
                        int a = p2.first - p2.second - x;
                        int b = p1.first - p1.second - y;

                        if(a <= b){
                            dp[i][j][k] = {p2.first, p2.second + x};
                        }
                        else{
                            dp[i][j][k] = {p1.first, p1.second + y};
                        }
                    }  

                    // debug(i, j, k, dp[i][j][k]);
                }
            }
        }

        // debug(dp[0][n - 1][0]);

        cout << dp[0][n - 1][0].first - dp[0][n - 1][0].second << "\n"; 
    }

    int32_t main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int tc = 1;
        //cin >> tc;
        for (int t = 1; t <= tc; t++) {
            // cout << "Case #" << t << ": ";
            solve();
        }
    }