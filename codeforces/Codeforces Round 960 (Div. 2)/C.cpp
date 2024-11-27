

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
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];

    auto check = [&](vector<int>& b){
        int value = accumulate(all(b), 0ll);
        map<int,int> mp;
        set<int> st;
        st.insert(0);
        for(int i = 0; i < n; i++){
            mp[b[i]] += 1;
            if(mp[b[i]] > 1){
                st.insert(b[i]);
            }
            b[i] = *prev(st.end(), 1);
        }
        return value;
    };
    int ans = check(a);
    ans += check(a);
    for(int i = 0; i < n; i++){
        ans += a[i] * (n - i);
    }
    cout << ans << "\n";
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