
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
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m;
int fac[19];
int p[19];


void preprocess(){
    fac[0] = 1;
    fac[1] = 1;
    for(int i = 2; i <= 18; i++){
        fac[i] = i * fac[i - 1];
    }

    p[0] = 1;
    for(int i = 1; i <= 18; i++){
        p[i] = (10 * p[i - 1]) % m;
    }
}




void solve() {
    cin >> n >> m;

    preprocess();

    vector<int> digits;
    int temp = n;
    while(temp != 0){
        digits.push_back(temp % 10);
        temp /= 10;
    }

    int sz = digits.size();
    int mx = (1 << sz) - 1;

    vector<vector<int>> dp(m, vector<int>(mx + 1, 0)), t(m, vector<int>(mx + 1, 0));

    for(int i = 0; i < sz; i++){
        int v = p[sz - 1];
        if(digits[i] == 0)continue;
        t[(digits[i] * v) % m][1 << i] += 1;
    }


    for(int i = 2; i <= sz; i++){

        for(int taken = 0; taken <= mx; taken++){
            if(__builtin_popcount(taken) != i - 1)continue;
            for(int mod = 0; mod < m; mod++){
                for(int j = 0; j < sz; j++){
                    if(!(taken & (1 << j))){    
                        int nmod = (mod + (digits[j] % m) * p[sz - i]) % m;
                        dp[nmod][taken | (1 << j)] += t[mod][taken];
                    }
                }
            }
        }

        for(int taken = 0; taken <= mx; taken++){
            for(int mod = 0; mod < m; mod++){
                t[mod][taken] = dp[mod][taken];
                dp[mod][taken] = 0;
            }
        }
    }

    int ans = t[0][mx];

    vector<int> freq(10, 0);
    for(int i = 0; i < sz; i++){
        freq[digits[i]]++;
    }

    for(int i = 0; i <= 9; i ++){
        ans  /= fac[freq[i]];
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}