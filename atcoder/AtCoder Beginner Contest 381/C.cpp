

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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> ones(n), twos(n);
    for(int i = 0; i < n; i++)if(s[i] == '2'){
    	int j = i;
    	while(j < n && s[j] == '2'){
    		j += 1;
    	}
    	for(int k = i; k < j; k++){
    		twos[k] = j - k;
    	}
    	i = j - 1;
    }
    for(int i = n - 1; i >= 0; i--) if(s[i] == '1'){
    	int j = i;
    	while(j >= 0 && s[j] == '1'){
    		j -= 1;
    	}
    	for(int k = j + 1; k <= i; k++){
    		ones[k] = (k - j);
    	}
    	i = j + 1;
    }
    // debug(ones, twos);
    int mx = 1;
    for(int i = 1; i < n - 1; i++) if(s[i] == '/'){
    	int mn = min(twos[i + 1], ones[i - 1]);
    	int len = 1 + 2 * mn;
    	mx = max(mx, len);
    }
    cout << mx << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}