

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
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<int> state(n + 1);
    for(int i = 1; i <= n; i++){
    	state[i] = s[i - 1] - '0';
    }
    vector<int> count(n + 1);
    for(int i = 0; i < q; i++){
		int b;
		cin >> b;
		count[b] += 1;
    }

    for(int i = 1; i <= n; i++){
    	if(count[i] == 0)
    		continue;
    	for(int j = i; j <= n; j += i) { 
    		state[j] += count[i];
    		state[j] %= 2;
    	}
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
    	if(state[i] == 1){
    		ans += 1;
    		for(int j = i; j <= n; j += i) { 
    			state[j] += 1;
    			state[j] %= 2;
    		}
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
        cout << "Case #" << t << ": ";
        solve();
    }
}