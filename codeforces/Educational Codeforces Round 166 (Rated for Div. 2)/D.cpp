

/* author: (    g)theoden42 */

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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pre(n + 1);
    for(int i = 0; i < n; i++){
    	pre[i + 1] += pre[i] + ((s[i] == '(') ? 1 : -1);
    }

    // debug(pre);

    multiset<int> mst;
    vector<int> count(n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	// debug(count);
    	ans += count[pre[i]];
    	// debug(i, ans);
    	count[pre[i]] += 1;
    	mst.insert(pre[i]);
    	while(!mst.empty() && *mst.begin() * 2 < pre[i]){
    		auto val = *mst.begin();
    		mst.erase(mst.begin());
    		count[val] -= 1;
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