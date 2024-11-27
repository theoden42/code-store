

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
    int n, q;
    cin >> n >> q;
    vector<int> p(n + 1);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        p[x] += 1;
    }
    for(int i = 1; i <= n; i++){
        p[i] += p[i - 1];
    }
    vector<int> f_ans(n + 1);

    auto check = [&](int mid, int x){
        int count = 0;
        count += p[min(n, mid)];
        for(int k = 1; k * x <= n; k++){
            count += p[min(n, k * x + mid)] - p[k * x - 1];
        }
        // debug(x, mid, count);
        if(n & 1)
            return (count >= (n + 1)/ 2);
        else 
            return (count >= (n / 2 + 1));
    };

    for(int x = 1; x <= n; x++){
        int lb = 0;
        int ub = x - 1;
        int ans = x - 1;
        while(lb <= ub){
            int mid = lb + (ub - lb) / 2;
            if(check(mid, x)){
                ans = mid;
                ub = mid - 1;
            } else {
                lb = mid + 1;
            }
        }
        f_ans[x] = ans;
    }
    for(int i = 1; i <= q; i++){
        int x;
        cin >> x;
        cout << f_ans[x] << " \n"[i == q];
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