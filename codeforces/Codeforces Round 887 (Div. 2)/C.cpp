

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
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	if(a[0] != 1){
		cout << 1 << "\n";
		return;
	}
	int flag = 1;
	for(int i = 0; i < n - 1; i++){
		if(a[i + 1] - a[i] != 1){
			flag = 0;
			break;
		}
	}
	if(flag){
		int ans = n * k + 1;
		cout << ans << "\n";
		return;
	}

	int pos = 1;
	for(int i = 1; i <= k; i++){
		int behind = pos;
		int low = 0;
		int high = 1e18;
		int ans = 1e18;
		while(low <= high){
			int mid = low + (high - low) / 2;
			auto it = upper_bound(all(a), mid);
			int del;
			if(it == a.begin()){
				del = 0;
			}
			else{
				it--;
				del = it - a.begin() + 1;
			}
			int rem = mid - del;
			if(rem < behind){
				low = mid + 1;
			}else if(rem >= behind){
				ans = mid;
				high = mid - 1;
			}
		}
		pos = ans;
	}

	cout << pos << "\n";


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