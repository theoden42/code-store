

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
	vector<int> vis(n);
	int ans = 0;
	int left = 0;
	int right = n - 1;
	while(left <= right){
		int flag = 0;
		int ind = -1;
		int mn = -1;
		for(int j = 0; j < n; j++){
			if(!vis[j]){
				int leftcost = a[j] * abs(left - j);
				int rightcost = a[j] * abs(right - j);

				if(leftcost > mn){
					mn = leftcost;
					flag = 0;
					ind = j;
				}
				if(rightcost > mn){
					mn = rightcost;
					flag = 1;
					ind = j;
				}
			}
		}
		assert(ind != -1);
		vis[ind] = 1;
		if(flag){
			ans += (a[ind] * abs(ind - right));
			right -= 1;
		} else {
			ans += (a[ind] * abs(ind - left));
			left += 1;
		}
	}

	cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //in >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}