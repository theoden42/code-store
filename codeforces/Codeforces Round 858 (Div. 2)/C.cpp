

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
    vector<int> a(2 * n);

    for(auto& x: a){
    	cin >> x;
    }

    sort(all(a));

    int ans = 0;
    for(int i = 0; i < 2 * n; i++){
    	ans += abs(a[i]);
    }


    if(n == 1){
    	cout << a[1] - a[0] << "\n";
    	return;
    }
    if(n == 2){
    	int count2 = 0;
    	for(int i = 0; i < 2 * n ; i++){
    		count2 += abs((a[i] - 2));
    	}
    	debug(count2);
    	ans = min({ans, count2});
    }
    if(n % 2 == 0){
    	int count = 0;
    	for(int i = 0; i < 2 * n; i++){
    		count += abs(a[i] + 1);
    	}
    	int x = 1e18;

    	for(int i = 0; i < 2 * n; i++){
    		int temp = count - abs(a[i] + 1) + abs(a[i] - n);
    		x = min(x, temp);
    	}

    	debug(x);

    	ans = min(ans, x);
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