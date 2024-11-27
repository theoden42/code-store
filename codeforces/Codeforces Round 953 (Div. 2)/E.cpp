

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
    string s, t;
    cin >> s >> t;
    vector<int> a(n), b(n), at(n), bt(n);
    for(int i = 0; i < n; i++){
    	a[i] = s[i] - '0';
    	b[i] = t[i] - '0';
    	at[i] = a[i];
    	bt[i] = b[i];
    }
    for(int i = 1; i < n - 1; i++){
    	if(a[i - 1] == 0 && a[i + 1] == 0){
    		bt[i] = 1;
    	}
    }
    for(int i = 1; i < n - 1; i++){
    	if(bt[i - 1] == 1 && bt[i + 1] == 1){
    		at[i] = 1;
    	}
    }
    vector<int> pref(n + 1);
    for(int i = 1; i <= n; i++){
    	pref[i] = pref[i - 1];
    	pref[i] += (at[i - 1] == 1);
    }
    // debug(at, bt);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
    	int l, r;
    	cin >> l >> r;
    	if(r - l <= 2){
    		vector<int> na(r - l + 1);
    		vector<int> nb(r - l + 1);
    		for(int j = l; j <= r; j++){
    			na[j - l] = a[j - 1];
    			nb[j - l] = b[j - 1];
    		}
    		for(int i = 1; i < r - l; i++){
    			if(na[i - 1] == 0 && na[i + 1] == 0)
    				nb[i] = 1;
    		}
    		for(int i = 1; i < r - l; i++){
    			if(nb[i - 1] == 1 && nb[i + 1] == 1)
    				na[i] = 1;
    		}
    		int count = 0;
    		for(int i = 0; i < r - l + 1; i++){
    			count += (na[i] == 1);
    		}
    		cout << count << "\n";
    	} else {
    		int nm = pref[r] - pref[l - 1];
    		if(at[l - 1] == 1 && a[l - 1] == 0)
    			nm -= 1;
    		if(at[r - 1] == 1 && a[r - 1] == 0 )
    			nm -= 1;
    		if(l > 1){
    			if(a[l - 2] == 0 && b[l - 1] == 0 && bt[l - 1] == 1){
    				if(a[l] == 0 && at[l] == 1){
    					nm -= 1;
    				}
    			}
    		}
    		if(r < n){
    			if(b[r - 1] == 0 && bt[r - 1] == 1){
    				if(a[r - 2] == 0 && at[r - 2] == 1)
    					nm -= 1;
    			}
    		}
    		cout << nm << "\n";
    	}
    }
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