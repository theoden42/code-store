

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
    int sum = accumulate(all(a), 0ll);

    sort(all(a));
	int md = (n + 1) / 2;
	md--;

	int ans = 1e18;
	if((n & 1) && md != 0){	
		int y = (n * a[md - 1] + a[md - 1]) - sum;
		if(y <= a[md - 1]){
			ans = min(ans, y);
		}
	}
	if(!(n & 1) && md != n - 1){
		int y = (n * a[md + 1] + a[md + 1] - sum);
		if(y >= a[md + 1]){
			ans = min(ans, y);
		}
	}

	int y = (n * a[md] + a[md] - sum);
	if((n & 1) && y >= a[md]){
		ans = min(ans, y);
	}
	else if(!(n & 1) && y <= a[md]){
		ans = min(ans, y);
	}

	if(sum % n == 0){
		int v = sum / n;
		vector<int> temp = a;
		temp.push_back(v);
		sort(all(temp));
		int ind = n / 2 + 1;
		if(temp[ind - 1] == v){
			ans = min(ans, v);
		}
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