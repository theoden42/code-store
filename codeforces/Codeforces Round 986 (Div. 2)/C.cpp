

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
	int n, m, v;
	cin >> n >> m >> v;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> pref(n + 1);
	for(int i = 1; i <= n; i++){
		pref[i] = pref[i - 1] + a[i - 1];
	}
	vector<int> dp(n + 1);
	dp[n] = 0;
	for(int i = n - 1; i >= 0; i--){
		int lb = i;
		int ub = n - 1;
		int ind = -1;
		while(lb <= ub){
			int mid = lb + (ub - lb) / 2;
			int sum = pref[mid + 1] - pref[i];
			if(sum >= v){
				ind = mid;
				ub = mid - 1;
			} else {
				lb = mid + 1;
			}
		}
		if(ind != -1){
			dp[i] = 1 + dp[ind + 1];
		}
	};
	int sum = 0;
	ordset<int> st;
	for(int i = 0; i < n; i++){
		sum += a[i];
		if(sum >= v){
			st.insert(i);
			sum = 0;
		}
	}	

	if(st.size() < m){
		cout << "-1\n";
		return; 
	}

	auto check = [&](int val){
		int mx = 0;
		for(int i = 0; i < n; i++){
			int lb = i;
			int ub = n - 1;
			int ind = -1;
			while(lb <= ub){
				int mid = lb + (ub - lb) / 2;
				int sum = pref[mid + 1] - pref[i];
				if(sum >= val){
					ind = mid;
					ub = mid - 1;
				} else {
					lb = mid + 1;
				}
			}
			if(ind == -1)
				continue;
			int count = st.order_of_key(i);
			count += dp[ind + 1];
			mx = max(mx, count);
		}
		return (mx >= m);
	};

	int lb = 1;
	int ub = 1e18;
	int ans = 0;
	while(lb <= ub){
		int mid = lb + (ub - lb) / 2;
		if(check(mid)){
			ans = mid;
			lb = mid + 1;
		} else {
			ub = mid - 1;	
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