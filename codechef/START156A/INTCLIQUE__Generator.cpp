

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
	int n = 20;
    vector<pair<int,int>> vp;
    set<int> st;
    while(vp.size() < 5){
    	int l = 1 + rng() % 10;
    	int r = l + rng() % (10 - l + 1);
    	if(l != r && st.find(l) == st.end() && st.find(r) == st.end()) {
    		vp.push_back({l, r});
    		st.insert(l);st.insert(r);
    	}
    }
    cout << vp.size() << "\n";
    for(auto [a, b]: vp){
    	cout << a << " " << b << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cout << 1 << "\n";
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}