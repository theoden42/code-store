

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
    vector<int> v(n);
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    }

    vector<int> temp = v;
    int ans = 0;

    for(int i = 1; i <= n; i++){
    	set<int> st;
    	for(int i = 0; i < n; i++){
    		if(v[i] == 1 && temp[i] == 1){
    			st.insert(i);
    		}
    	}
    	if(st.empty())
    		break;

    	int ind = -1;
    	int mxval = n + 1;
    	for(int j = 0; j < n; j++){
    		if(v[j] == 0 && temp[j] == 0){
    			auto it = st.upper_bound(j);
    			int val = n + 1;
    			if(it != st.end()){
    				val = min(val, abs(*it - j));
    			}
    			if(it != st.begin()){
    				it--;
    				val = min(val, abs(*it - j));
    			}
    			if(val < mxval){
    				mxval = val;
    				ind = j;
    			}
    		}
    	}
    	if(ind == -1)
    		break;

    	auto it = st.upper_bound(ind);
    	int a = n + 1;
    	int b = n + 1;

    	if(it != st.end()){
    		int d = abs(*it - ind);
    		a = d;
    	}
    	if(it != st.begin()){
    		it--;
    		int d = abs(*it - ind);
    		b = d;
    	}

    	if(a < b){
    		int x = *st.upper_bound(ind);
    		temp[x] = 0;
    		temp[ind] = 1;
    		ans += abs(x - ind);
    	} else { 
    		int x = *(--st.upper_bound(ind));
    		temp[x] = 0;
    		temp[ind] = 1;
    		ans += abs(x - ind);
    	}
    	debug(temp);
    }



    cout << ans << "\n";
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