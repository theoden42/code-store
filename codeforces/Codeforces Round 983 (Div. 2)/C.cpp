

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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(all(a));
	int count = n;
	auto get = [&](int i){
		if(i >= n - 2){
			return 0;
		} 
		int lb = i + 2;
		int ub = n - 1;
		int ans = i + 1;
		while(lb <= ub){
			int mid = lb + (ub - lb) / 2;
			if(a[mid] < a[i] + a[i + 1]){
				ans = mid;
				lb = mid + 1;
			} else {
				ub = mid - 1;
			}
		}
		return (n - ans - 1);
	};
	for(int i = 0; i < n; i++){
		int temp = i;
		temp += get(i);
		count = min(count, temp);
	}
	cout << count << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}