

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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(n + 1);
    for(int i = 0; i < n; i++){
    	p[i + 1] = p[i];
    	p[i + 1] += (s[i] == '1');
    }
    map<int,int> count;
    int ans = 0;
    count[0] = 1;
    for(int i = 1; i <= n; i++){
    	int v = 2 * p[i] - i;
    	int x = count[v];
    	int y = (n - i + 1);
    	ans += (x * y) % MOD;
    	ans %= MOD;
    	count[v] += (i + 1);
    	count[v] %= MOD;
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