

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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	for(int j = 30; j >= 0; j--){
    		int val = (1 << j);
    		if(a[i] % val == 0){
    			// debug(a[i], val);
    			mp[j].push_back(i);
    			break;
    		}
    	}
    }
    // debug(mp[2]);

    for(int i = 0; i < q; i++){
    	int y;
    	cin >> y;
		for(int x = 30; x >= y; x--){
			for(auto in: mp[x]){
	    		a[in] += (1 << (y - 1));
	    		mp[y - 1].push_back(in);
	    	}
	    	mp[x].clear();
		}

    }

    for(int i = 0; i < n; i++){
    	cout << a[i] << " ";
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