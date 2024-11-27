

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
    vector<int> pref(2 * k + 1, 0);

    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	int rem = a[i] % (2 * k);
    	int lb = rem;
    	int ub = (rem + k - 1) % (2 * k);
    	if(lb <= ub){
    		pref[lb] += 1;
    		pref[ub + 1] -= 1;
    	} else {
    		pref[lb] += 1;
    		pref[2 * k] -= 1;
    		pref[0] += 1;
    		pref[ub + 1] -= 1;
    	}
    }
    sort(all(a));
    int md = -1;
    for(int i = 1; i < 2 * k + 1; i++){
    	pref[i] += pref[i - 1];
    }
    set<int> st;
    for(int i = 0; i < 2 * k; i++){
    	if(pref[i] == n){
    		st.insert(i);
    	} 
    }
    if(st.empty()){
    	cout << "-1\n";
    	return;
    }
    int mx = a.back();
    while(st.find(mx % (2 * k)) == st.end()){
    	mx += 1;
    }
    cout << mx << "\n";
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