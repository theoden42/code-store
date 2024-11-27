

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
    vector<vector<int>> flavor(n + 1);
    for(int i = 0; i < n; i++){
    	int f, s;
    	cin >> f >> s;
    	flavor[f].push_back(s);
    }
    for(int i = 1; i <= n; i++){
    	sort(all(flavor[i]));
    }

    int mn = 0ll;


    for(int i = n; i >= 1; i--){
    	if(flavor[i].size() >= 2){
    		int sz = flavor[i].size();
    		mn = max(mn, flavor[i][sz - 1] + flavor[i][sz - 2] / 2);
    	}
    }
    multiset<int> st;
    for(int i = n; i >= 1; i--){
    	if(flavor[i].size() != 0){
    		st.insert(flavor[i].back());
    	}
    }	

    if(st.size() >= 2){
    	auto it1 = --st.end();
    	int ans = *it1;
    	--it1;
    	ans += *it1;
    	mn = max(mn, ans);
    }
    cout << mn << "\n";
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