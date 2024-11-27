

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
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    a--;
    b--;
    vector<pair<int,int>> c(n);
    for(int i = 0; i < n; i++){
    	cin >> c[i].first >> c[i].second;
    }

    int mn = abs(c[a].first - c[b].first) + abs(c[a].second - c[b].second);

    int mna = 1e18;
    int mnb = 1e18;

    for(int i = 0; i < k; i++){
    	int disa = abs(c[i].first - c[a].first) + abs(c[i].second - c[a].second);
    	int disb = abs(c[i].first - c[b].first) + abs(c[i].second - c[b].second);
    	mna = min(mna, disa);
    	mnb = min(mnb, disb);
    }

    mn = min(mn, mna + mnb);
    cout << mn << "\n";
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