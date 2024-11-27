

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
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i];
    }
    sort(all(x));
    sort(all(y));

    debug(x, y);

    vector<int> prex(n + 1), prey(n + 1);
    for(int i = 1; i <= n; i++){
    	prex[i] = prex[i - 1] + x[i - 1];
    	prey[i] = prey[i - 1] + y[i - 1];
    }

    auto check = [&](int mid){
        debug(mid);
    	vector<int> sumx(n), sumy(n);
        for(int i = 0; i < n; i++){
            int left = i;
            int right = lower_bound(all(x), x[i] + mid + 1) - x.begin();
            int before = (left * x[i] - prex[left]);
            int after = prex[n] - prex[right] - (n - right) * x[i];
            sumx[i] = before + after;
        }

        for(int i = 0; i < n; i++){
            int left = i;
            int right = lower_bound(all(y), y[i] + mid + 1) - y.begin();
            int before = left * y[i] - prey[left];
            int after = prey[n] - prey[right] - (n - right) * y[i];
            sumy[i] = before + after;
        }

        debug(sumx, sumy);

        int total = *min_element(all(sumx)) + *min_element(all(sumy));
        return (total <= k);
    };

    int lb = 0;
    int ub = 1e18;
    int ans = ub;
    while(lb <= ub){
    	int mid = (lb + ub) / 2;
    	if(check(mid)){
    		ans = mid;
    		ub = mid - 1;
    	} else {
    		lb = mid + 1;
    	}
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