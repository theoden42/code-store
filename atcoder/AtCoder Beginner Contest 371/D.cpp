

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
    vector<int> x(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++)
    	cin >> x[i];
    for(int i = 0; i < n; i++)
    	cin >> p[i];
    vector<int> pref(n + 1);
    for(int i = 1; i <= n; i++){
    	pref[i] = pref[i - 1];
    	pref[i] += p[i - 1];
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
    	int l, r;
    	cin >> l >> r;
    	auto ind1 = lower_bound(all(x), l);
    	auto ind2 = upper_bound(all(x), r);
        int i1, i2;
        if(ind2 == x.begin()){
            cout << "0\n";
            continue;
        } else {
            ind2--;
            i2 = (ind2 - x.begin()) + 1;
        }
        if(ind1 == x.begin()){
            i1 = 0;
        } else {
            --ind1;
            i1 = (ind1 - x.begin()) + 1;
        }

    	int ans = pref[i2] - pref[i1];
    	cout << ans << "\n";
    }
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