

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
    vector<int> v(n);
    multiset<int> ones;
    int sum = 0;
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    	sum += v[i];
    	if(v[i] == 1){
    		ones.insert(i);
    	}
    }
    for(int i = 0; i < q; i++){
    	int t;
    	cin >> t;
    	if(t == 1){
    		int s;
    		cin >> s;
    		if(s > sum){
    			cout << "NO\n";
    			continue;
    		}
    		if((s % 2) == (sum % 2)){
    			cout << "YES\n";
    		} else if(!ones.empty()) {
    			int left = *ones.begin();
    			int right = n - 1 - *ones.rbegin();
    			int mxval = sum - min(left, right) * 2;
    			if(s <= mxval){
    				cout << "YES\n";
    			} else {
    				cout << "NO\n";
    			}
    		} else {
    			cout << "NO\n";
    		}
    	} else {
    		int i, val;
    		cin >> i >> val;
    		i--;
    		if(v[i] == 1){
    			ones.erase(ones.find(i));
    		} 
    		sum -= v[i];
    		v[i] = val;
    		sum += v[i];
    		if(v[i] == 1){
    			ones.insert(i);
    		}
    	}
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