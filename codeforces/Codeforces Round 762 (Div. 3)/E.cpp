

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
    vector<int> a(n + 1);
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	a[x] += 1;
    }

    vector<int> prevval(n + 1, 0);
    multiset<int> mst;
    for(int j = 0; j <= n; j++){
    	int sum = a[j];
    	int sum2 = 0;
    	if(j != 0){
    		if(prevval[j - 1] == -1 || mst.empty()){
    			cout << "-1 ";
    			continue;
    		} else {
    			int x = *(--mst.end());
    			sum2 += (j - 1 - x);
    			mst.erase(--mst.end());
    			sum2 += prevval[j - 1];
    			prevval[j] = sum2;
    		}
    	}
    	cout << (sum + sum2) << " ";
    	for(int k = 1; k <= a[j]; k++){
    		mst.insert(j);
    	}
    }
    cout << "\n";
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