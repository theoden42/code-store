

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
	vector<int> pre(n + 1);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i - 1];
	}

	vector<int> change;
	for(int i = 0; i < n - 1; i++){
		if(a[i] != a[i + 1]){
			change.push_back(i);
		}
	}


	auto checkright = [&](int i, int mid){
		int sum = pre[mid + 1] - pre[i + 1];
		if(sum <= a[i])
			return false;

		auto c = lower_bound(all(change), mid);
		if(c == change.begin())
			return false;


		--c;
		if(*c < i){
			return false;
		} else if(*c == i && a[i + 1] <= a[i]){
			return false;
		} else {
			return true;
		}
	};

	auto checkleft = [&](int i, int mid){
		int sum = pre[i] - pre[mid];
		if(sum <= a[i])
			return false;

		auto c = lower_bound(all(change), mid);
		if(c == change.end())
			return false;
		
		if(*c >= i){
			return false;
		} else if(*c == i - 1 && a[i - 1] <= a[i]){
			return false;
		} else {
			return true;
		}
	};

	vector<int> final(n);

	for(int i = 0; i < n; i++){
		int lb = i + 1;
		int ub = n - 1;
		int ans = 1e9;
		while(lb <= ub){
			int mid = (lb + ub) / 2;
			if(checkright(i, mid)){
				ans = mid - i;
				ub = mid - 1;
			} else {
				lb = mid + 1;
			}
		} 

		lb = 0;
		ub = i - 1;
		int ans2 = 1e9;
		while(lb <= ub){
			int mid = (lb + ub) / 2;
			if(checkleft(i, mid)){
				ans2 = i - mid;
				lb = mid + 1;
			} else {
				ub = mid - 1;
			}
		}
		final[i] = min(ans, ans2);
	}

	for(int i = 0; i < n; i++){
		cout << ((final[i] == 1e9) ? -1 : final[i]) << " \n"[i == n - 1];
	}
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