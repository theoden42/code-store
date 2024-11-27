

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
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int,int>> vp(k);
    for(int i = 0; i < k; i++){
    	cin >> vp[i].first >> vp[i].second;
    }
    sort(all(vp));
    int ind = 0;
    ordset<int> st;
    int mn = 1e9, mx = 0, mnind = -1, mxind = -1; 
    for(int end = d - 1; end <= n; end++){
    	while(ind < k && vp[ind].first < end){
    		st.insert(vp[ind].second);
    		ind += 1;
    	}
    	int left = end - d + 1;
    	int sz = st.size() - st.order_of_key(left);
    	if(sz > mx){
    		mx = sz;mxind = left;
    	} 
    	if(sz < mn){
    		mn = sz;mnind = left;
    	}
    }

    cout << mxind << " " << mnind << "\n"; 
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}