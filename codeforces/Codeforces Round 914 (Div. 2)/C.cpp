

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
	if(k >= 3){
		cout << "0\n";
		return;
	}

	vector<int> temp;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int x = abs(a[i] - a[j]);
			temp.push_back(x);
		}
	}
	sort(all(a));
	sort(all(temp));
	int mn = min(a[0], temp[0]);
	if(k == 1){
		cout << mn << "\n";
		return;
	} else {
		for(int i = 0; i < n; i++){
			auto it1 = lower_bound(all(temp), a[i]);
			if(it1 != temp.begin()){
				int d = a[i] - *(--it1);
				// debug(d, *it1);
				mn = min(mn, d);
			}
			it1 = lower_bound(all(temp), a[i]);
			if(it1 != temp.end()){
				int d = *it1 - a[i];
				// debug(d, *it1);
				mn = min(mn, d);
			}
		}
		cout << mn << "\n";
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