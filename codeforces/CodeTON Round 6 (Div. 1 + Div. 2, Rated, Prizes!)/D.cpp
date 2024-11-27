
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
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    for(int i = n - 2; i >= 0; i--){
        c[i] = min(c[i], c[i + 1]);
    }
    int k;
    cin >> k;
    vector<int> ans(n);
    int curr = k / c[0];
    ans[0] = curr;
    k -= curr * c[0];
    for(int i = 1; i < n; i++){
        int d = c[i] - c[i - 1];
        int nw = (d == 0) ? curr : min(curr, k / d);
        // i can apply atmost nw here
        ans[i] = nw;
        curr = nw;
        k -= curr * d;
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
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