

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
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int mx = *max_element(all(a));
    vector<int> pref(mx + 1);

    for(int i = 0; i < n; i++){
        int cf = 0;

        if(i == 0 || a[i] > a[i - 1])
            cf += 1;
        if(i < n - 1 && a[i] < a[i + 1])
            cf -= 1;

        pref[a[i]] += cf;
    }


    for(int i = 1; i <= mx; i++){
        pref[i] += pref[i - 1];
    }

    for(int k = 1; k <= mx; k++){
        int ans = 0;
        for(int mul = 1; mul <= (mx + k - 1) / k; mul += 1){
            int left = k * (mul - 1) + 1;
            int right = min(mx, (k * mul));

            int cof = pref[right] - pref[left - 1];
            ans += (mul * cof);
        }   

        cout << ans << " \n"[k == mx];
    }

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