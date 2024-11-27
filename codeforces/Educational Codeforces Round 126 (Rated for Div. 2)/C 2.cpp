

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
    vector<int> h(n);
    for(int i = 0; i < n; i++){
    	cin >> h[i];
    }

    sort(all(h));

    int l = 0;
    int u = 1e18;
    int mn = 1e18;

    function<int(int)> check = [&](int x)->int{
    	int two = x / 2;
    	int one = (x + 1) / 2;

    	int val = h[n - 1];
    	int cnt1 = 0;
    	int cnt2 = 0;


    	for(int i = 0; i < n; i++){
    		if((val & 1) != (h[i] & 1)){
    			// debug(h[i]);
    			cnt1++;
    		}
    		cnt2 += (val - h[i]) / 2;
    	}


    	debug(cnt1, cnt2, x);
    	if(cnt1 <= one && (cnt2 <= (two + (one - cnt1) / 2))){
    		return true;
    	}

    	val = h[n - 1] + 1;
    	cnt1 = 0;
    	cnt2 = 0;

    	for(int i = 0; i < n; i++){
    		if((val & 1) != (h[i] & 1)){
    			cnt1++;
    		}
    		cnt2 += (val - h[i]) / 2;
    	}

    	if(cnt1 <= one && cnt2 <= (two + (one - cnt1) / 2)){
    		return true;
    	}

    	return false;

    };

    while(l <= u){
    	int mid = l + (u - l) / 2;
    	if(check(mid)){
    		mn = mid;
    		u = mid - 1;
    	}else{
    		l = mid + 1;
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