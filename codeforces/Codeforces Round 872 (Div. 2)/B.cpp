

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
    vector<int> b(n * m);
    for(int i = 0; i < n * m; i++){
    	cin >> b[i];
    }

    sort(all(b));
    int sz = m * n;
    int c = min(n, m);


    int mn1 = b[0];
    int mn2 = b[1];
    int mx1 = b[m * n - 1];
    int mx2 = b[m * n - 2];

   	int sum = (c - 1) * (mx2 - mn1);
   	sum += (n * m - c) * (mx1 - mn1);

   	int sum2 = (c - 1) * (mx1 - mn2);
   	sum2 += (n * m - c) * (mx1 - mn1);

   	cout << max(sum, sum2) << "\n";
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