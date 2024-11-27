

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
    string s;
    cin >> s;
    int n = s.size();
    int ans = (n * (n - 1)) / 2;
    vector<int> f(26);
    int flag = 0;
    for(auto c: s){
    	f[c - 'a'] += 1;
    }
    for(int i = 0; i < 26; i++){
		if(f[i] > 1)
			flag = 1;
    	int t = (f[i] * (f[i] - 1)) / 2;
    	ans -= t;
    }

    if(flag)
    	ans += 1;

    cout << max(1ll, ans) << "\n";
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