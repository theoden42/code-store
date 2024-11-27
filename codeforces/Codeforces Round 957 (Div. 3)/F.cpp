

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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    int count = 1;

    set<int> st;
    for(int i = 0; i < n; i++){
    	if(x % a[i] != 0)
    		continue;
    	int f = 0;
    	for(auto v: st){
    		if(v * a[i] == x){
    			f = 1;
    			break;
    		}
    	}
    	if(f){	
    		st.clear();
    		count += 1;
    	} else {
    		vector<int> tarr;
    		for(auto v: st){
    			int temp = v * a[i];
    			if(x % temp == 0)
    				tarr.push_back(temp);
    		}
    		for(auto v: tarr)
    			st.insert(v);
    	}
    	st.insert(a[i]);
    }

    cout << count << "\n";
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