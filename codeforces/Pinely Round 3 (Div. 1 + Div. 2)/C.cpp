

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
    vector<int> l(n), r(n);
    vector<int> c(n);

    for(int i = 0; i < n; i++){
    	cin >> l[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> r[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> c[i];
    }

    sort(all(c));

    vector<pair<int,int>> pnt;
    for(int i = 0; i < n; i++){
    	pnt.push_back({l[i], 0});
    }
    for(int i = 0; i < n; i++){
    	pnt.push_back({r[i], 1});
    }

    sort(all(pnt));
    stack<int> st;
    vector<int> dist;
    int ans = 0;
    for(auto [x, t]: pnt){
    	if(t == 1){
    		int val = st.top();
    		st.pop();
    		dist.push_back(x - val);
    	} else {
    		st.push(x);
    	}
    }
    sort(all(dist));
    for(int i = 0; i < n; i++){
    	int temp = (dist[i] * c[n - i - 1]);
    	// debug(temp);
    	ans += temp;
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