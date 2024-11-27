

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
    vector<int> t1, t2;
    t1.push_back(-INF);
    t2.push_back(-INF);
    for(int i = 0; i < n; i++){
    	if(t1.back() >= a[i] && t2.back() >= a[i]){
	    	if(t1.back() < t2.back()){
	    		t1.push_back(a[i]);
	    	} else {
	    		t2.push_back(a[i]);
	    	}
    	} else if(t1.back() < a[i] && t2.back() < a[i]){
	    	if(t1.back() < t2.back()){
    			t1.push_back(a[i]);
	    	} else {
	    		t2.push_back(a[i]);
	    	}
    	} else if(t1.back() >= a[i]){
    		t1.push_back(a[i]);
    	} else {
    		t2.push_back(a[i]);
    	}

    }
    int ans = 0;
    for(int i = 2; i < t1.size(); i++){
    	if(t1[i] > t1[i - 1]){
    		ans += 1;
    	}
    }
    for(int i = 2; i < t2.size(); i++){
    	if(t2[i] > t2[i - 1]){
    		ans += 1;
    	}
    }

    // debug(t1, t2);

    cout << ans << "\n";
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