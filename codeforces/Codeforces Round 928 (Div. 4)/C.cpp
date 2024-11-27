

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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#define int long long

int dfs(int n){
	if (n < 10)
      return (1ll * (n*(n+1))/2);
 
    int d = log10(n);

    vector<int> a(d + 1);
    a[0] = 0, a[1] = 45;
    for (int i=2; i<=d; i++)
        a[i] = a[i-1]*10 + 45 * ceil(pow(10, i-1));
 
    int p = ceil(pow(10, d));
    int m = n / p;
    int ans = m * a[d] + (m * (m - 1) / 2) * p + m * (1 + n % p) + dfs(n % p);
    return ans;
}

void solve()
{
	int n;
	cin >> n;
	int v = dfs(n);
	cout << v << "\n";

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