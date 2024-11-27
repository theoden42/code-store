

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
    multiset<int> mst;
    for(int i = 0; i < n; i++){
    	if(a[i] == 0){
    		mst.insert(i);
    	}
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] == 0)
    		continue;
    	int j = i;
    	int flag = 0;
    	while(j < n && a[j] != 0){
    		if(a[j] == 2){
    			flag = 1;
    		}
    		j += 1;
    	}
    	ans += 1;
    	if(flag){
    		if(mst.find(i - 1) != mst.end()){
    			mst.erase(i - 1);
    		} 
    		if(mst.find(j) != mst.end()){
    			mst.erase(j);
    		}
    	} else {
    		if(mst.find(i - 1) != mst.end()){
    			mst.erase(i - 1);
    		} else if(mst.find(j) != mst.end()){
    			mst.erase(j);
    		}
    	}
    	i = j - 1;
    }

    ans += mst.size();
    cout << ans << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}