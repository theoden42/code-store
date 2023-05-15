
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

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> size(n, 0);
    for(int i = 0; i < n; i++){
        cin >> size[i];
    }
    vector<int> dp(n + 1, 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j * j <= i; j++){
            if(i % j == 0){
                if(size[j - 1] < size[i - 1]){
                    dp[i] = max(dp[i], dp[j] + 1); 
                }
                if(size[i / j - 1] < size[i - 1]){
                    dp[i] = max(dp[i], dp[i / j] + 1);
                }
            }
        }
    }
    int mx = 0;
    for(auto& x: dp){
        mx = max(mx, x);
    }
    cout << mx << "\n";
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