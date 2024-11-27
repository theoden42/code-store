

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
    int x;
    cin >> x;
    int t = x;
    int count = 0;
    vector<int> ans;
    while(t != 0){
    	count += 1;
    	t >>= 1;
    }

    for(int i = 1; i <= count - 1; i++){
    	ans.push_back(i);
    }
    for(int i = count - 2; i >= 0; i--){
    	if(x >> i & 1){
    		ans.push_back(i + 1);
    	}
    }
    cout << ans.size() << "\n";
    for(auto a: ans){
    	cout << a << " ";
    }
    cout << "\n";
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