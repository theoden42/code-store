

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

    int sum = 0;
    int sum2 = 0;
    int count = 0;
    multiset<pair<int,int>> mst;

    for(int i = n - 1; i >= 0; i--){
    	int rem = a[i] - sum;	
    	if(rem > 0){
    		if(i >= k - 1){
    			int num = (rem + k - 1) / k;
	    		count += num;
	    		sum += num * k;
	    		sum2 += num;
	    		mst.insert({i, num});
    		}
    		else{
    			int num = (rem + i) / (i + 1);
	    		count += num;
	    		sum += (i + 1) * num;
	    		sum2 += num;
	    		mst.insert({i, num});
    		}
    	}

    	while(!mst.empty()){
    		auto it = --mst.end();
    		if(it->first >= i + k){
    			sum2 -= it->second;
    			mst.erase(it);
    		}
    		else{
    			break;
    		}
    	}
    	sum -= sum2;
    }

    cout << count << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}