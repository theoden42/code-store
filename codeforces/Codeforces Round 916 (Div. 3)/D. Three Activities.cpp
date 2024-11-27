
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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];

    multiset<pair<int,int>> mstb, mstc;
    for(int i = 0; i < n; i++){
        mstb.insert({b[i], i});
        mstc.insert({c[i], i});
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        mstb.erase({b[i], i});
        mstc.erase({c[i], i});
        auto [val1, ind1] = *(--mstb.end());
        auto [val2, ind2] = *(--mstc.end());
        int temp = 0;
        if(ind1 != ind2){
            temp = a[i] + val1 + val2;
        } else {
            auto [val3, ind3] = *(--(--mstb.end()));
            auto [val4, ind4] = *(--(--mstc.end()));
            temp = a[i] + max(val1 + val4, val2 + val3);
        }
        ans = max(ans, temp);
        mstb.insert({b[i], i});
        mstc.insert({c[i], i});
    }
    
    cout << ans << "\n";
        
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
