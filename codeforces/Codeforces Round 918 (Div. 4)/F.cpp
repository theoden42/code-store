

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
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i] >> b[i];
    }

    vector<vector<int>> points;
    for(int i = 0; i < n; i++){
    	points.push_back({a[i], 0, i});
    	points.push_back({b[i], 1, i});
    }

    ordset<int> st;	

    int ans = 0;
    sort(all(points));
    for(auto v: points){
    	int val = v[0];
    	int type = v[1];
    	int ind = v[2];
    	if(!type){
    		ans += ((int)st.size() - st.order_of_key(b[ind]));
    		st.insert(b[ind]);
    	} 
    }

    cout << ans << "\n";
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