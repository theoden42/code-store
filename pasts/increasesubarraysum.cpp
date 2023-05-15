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

    void solve() {
        int n, x;
        cin >> n >> x;
        vector<int> ele(n, 0);
        for(int i = 0; i < n; i++){
            cin >> ele[i];
        }
        vector<int> msum(n + 1, 0);
        for(int i = 1; i <= n; i++){
            int mxsum = -1e9;
            int sum = 0;
            for(int j = 0; j < i; j++){
                sum += ele[j];
            }
            mxsum = max(sum, mxsum);
            for(int j = 1; j <= n - i; j++){
                debug(mxsum);
                sum -= ele[j - 1];
                sum += ele[j + i - 1];
                mxsum = max(mxsum, sum);
            }
            msum[i] = mxsum;
        }
        debug(msum);
        for(int k = 0; k <= n; k++){
            int mx = 0;
            for(int i = 0; i <= n; i++){
                mx = max(mx, msum[i] + min(k, i) * x);
            }
            cout << mx << " ";
        }
        cout << "\n";
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