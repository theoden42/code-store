

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
    string s;
    cin >> s;
    int n = s.size();

    int num = 0;
    int state = 1;
    int plus = 0;
    int minus = 0;
    int mxchange = 0;
    int mnchange = 0;
    int mnsorted = 0;
    int mxsorted = 0;

    for(int i = 0; i < n; i++){
    	if(s[i] == '+'){
    		num++;
    	} else if(s[i] == '-'){
    		num--;
    	} else if(s[i] == '1'){
    		if(state == 1) {
    			mxsorted = num;
    			mnsorted = num;
    		} else {
    			if(!(num >= mnsorted && num <= mxsorted)){
    				cout << "NO\n";
    				return;
    			}
    			mxsorted = num;
    			mnsorted = num;
    			state = 1;
    		}
    		mxchange = 0;
    		mnchange = 0;
    	} else {
    		if(state == 0){
    			mnsorted = mnchange;	
    			mxsorted = min(mxsorted, num);
    			mnsorted = min(mnsorted, num);
    		} else {
    			if(num == mnchange){
    				cout << "NO\n";
    				return;
    			}
    			if(mnchange >= mnsorted){
    				cout << "NO\n";
    				return;
    			}
    			mnsorted = mnchange;
    			mxsorted = num - 1;
    			state = 0;
    		}
    		mxchange = 0;
    		mnchange = 0;
    	}

    	mxchange = max(mxchange, num);
    	mnchange = min(mnchange, num);
    }


    cout << "YES\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}