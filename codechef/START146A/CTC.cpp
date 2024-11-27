

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

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> pre(n, vector<int>(m + 1, 0));
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            pre[j] = pre[j - 1] + a[i][j - 1];
        }
    }
    vector<int> mx(n, 1e18);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int lsum = pre[j + 1] - pre[0];
            int rsum = pre[n] - pre[j];
            mx[i] = min(  mx[i ], max(lsum, rsum));
        }
    }
    multiset<int> mst;

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