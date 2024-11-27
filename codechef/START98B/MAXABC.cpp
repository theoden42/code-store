

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
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }

    vector<int> prefix(n + 1);
    for(int i = 1; i <= n; i++){
    	int s = a[i - 1] + b[i - 1];
    	prefix[i] = prefix[i - 1] + s;
    }

    multiset<pair<int,int>> mst;
    mst.insert({n, prefix[n]});
    int mx = max(0ll, prefix[n]);


    int changeind = 1;

    set<pair<int,int>> indices;

    for(int i = n; i >= 1; i--){
    	int s = a[i] + b[i];
		int mxsum = *(--mst.end());
		int sum = mxsum - prefix[i - 1];
		int sum2 = mxsum - prefix[i - 1] - min(a[i - 1], b[i - 1]);


		int val = max(sum, sum2);
		if(val > mx){
			mx = val;
			indices.clear();
		}

		mx = max({mx, sum, sum2});
		mst.insert(prefix[i]);
		mst.insert(prefix[i] - min(a[i - 1], b[i - 1]));
    }

    cout << mx << "\n";

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