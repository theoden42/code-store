
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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> vals(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            vals[i][j] = (s[j] == '*') ? 1 : 0;
        }
    }
    vector<vector<int>> pf(n + 1, vector<int> (n + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            pf[i][j] = pf[i - 1][j] + pf[i][j - 1] + vals[i - 1][j - 1];
            pf[i][j] -= pf[i - 1][j - 1];
        }
    }

    for(int i = 1; i <= q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = pf[c][d] - pf[a - 1][d] - pf[c][b - 1] + pf[a - 1][b - 1];
        cout << ans << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
