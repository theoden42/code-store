

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

    // debug(a);
    auto count = [&](int i, int j, int k){
    	int sum = 0;
    	for(int ind = 0; ind < n; ind++){
    		int l = a[ind] % 3;
 			int s = 0;
    		if(ind % 3 == 0){
    			s = (i - l + 3) % 3;
    		}else if(ind % 3 == 1){
    			s = (j - l + 3) % 3;
    		}else{
    			s = (k - l + 3) % 3;
    		}
    		// debug(s);
    		sum += s;
    	}
    	return sum;
    };

    int mn = 3 * n;
    for(int i = 0; i < 3; i++){
    	for(int j = 0; j < 3; j++){
    		for(int k = 0; k < 3; k++){
    			int s = i + j + k;
    			if(s % 3 != 0)
    				continue;
				mn = min(mn, count(i, j, k));
    		}
    	}
    }
    cout << mn << "\n";
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