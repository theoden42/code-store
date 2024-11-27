

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
	int n, m, d;
	cin >> n >> m >> d;
	vector<int> a(m);
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}

	int mxdiff = -1e18;
	vector<int> indices;
	for(int i = 0; i < m; i++) {
		if(i == 0) { 
			int diff = 0;
			if(a[i] == 1){
				diff = 0;
			} else {
				int left = (a[i] - 1 - 1) / d;
				int right = (a[i + 1] - a[i] - 1) / d;
				int total = left + right + 1;
				int lst = (a[i + 1] - 2) / d;
				diff = total - lst;
			}	
			if(mxdiff < diff) { 
				indices.clear();
				mxdiff = diff;
				indices.push_back(i);
			} else if(mxdiff == diff){
				indices.push_back(i);
			}
		} else if(i == m - 1) {
			int left = (a[i] - a[i - 1] - 1) / d;
			int right = (n - a[i]) / d;
			int total = left + right + 1;
			int lst = (n - a[i - 1]) / d;
			int diff = total - lst;
			if(mxdiff < diff) { 
				indices.clear();
				mxdiff = diff;
				indices.push_back(i);
			} else if(mxdiff == diff){
				indices.push_back(i);
			}
		} else { 
			int lst = (a[i + 1] - a[i - 1] - 1) / d;
			int left = (a[i] - a[i - 1] - 1) / d;
			int right = (a[i + 1] - a[i] - 1) / d;
			int total = left + right + 1;
			int diff = total - lst;
			if(mxdiff < diff){
				indices.clear();
				mxdiff = diff;
				indices.push_back(i);
			} else if(mxdiff == diff){
				indices.push_back(i);
			}
		}
	}

	int sum = m;
	if(a[0] == 1){
		sum -= 1;
	}
	int lst = 1;
	for(int i = 0; i < m; i++) {
		int tempcount = (a[i] - lst - 1) / d;
		sum += tempcount;
		lst = a[i];
	}
	sum += (n - lst) / d;
	sum -= mxdiff;
	cout << sum + 1 << " " << indices.size() << "\n";

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