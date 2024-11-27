

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
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0; i <n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(all(b));
    vector<int> pre(m + 1);
    for(int i = 1; i <= m; i++){
    	pre[i] = pre[i - 1] + b[i - 1];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
    	int maxvalue = p - a[i];
    	int count = upper_bound(all(b), maxvalue) - b.begin();
		int sum = 0;
		if(count > 0){
			sum += (pre[count]) + a[i] * (count);	
		}
		sum += (m - count) * p;
		ans += sum;
    }

    cout << ans << "\n";
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