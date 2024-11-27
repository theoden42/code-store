

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
    int pos, val;
    cin >> pos >> val;

    set<int> st;
    if(pos == val){
    	st.insert(pos);
    } 
    if((val + pos) % 2 == 0){
    	int k = (val + pos) / 2;
    	if(val <= k){
    		st.insert(k);
    	}
    }

    int v = pos - val;
    auto get = [&](int f)->ll{
    	if(f & 1)
    		return -1;
    	f += 2;
    	return f / 2;
    };

    for(int i = 1; i * i <= v; i++){
    	if(v % i == 0){
    		int f1 = i;
    		int f2 = v / i;

    		int x1 = get(f1);
    		int x2 = get(f2);

    		if(x1 != -1 && val <= x1){
    			st.insert(x1);
    		} 
    		if(x2 != -1 && val <= x2){
    			st.insert(x2);
    		}
    	}
    }

    v = pos + val - 2;
    for(int i = 1; i * i <= v; i++){
    	if(v % i == 0){
    		int f1 = i;
    		int f2 = v / i;

    		int x1 = get(f1);
    		int x2 = get(f2);

    		if(x1 != -1 && val <= x1){
    			st.insert(x1);
    		} 
    		if(x2 != -1 && val <= x2){
    			st.insert(x2);
    		}
    	}
    }

    cout << st.size() << "\n";

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