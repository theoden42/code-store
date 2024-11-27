

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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    string s;
    cin >> s;
    int left = 0;
    int right = n - 1;
    for(auto c: s){
    	if(c == 'L')
    		left += 1;
    	else 
    		right -= 1;
    }
    int x = 1;
    for(int i = left; i <= right; i++){
    	x *= a[i];
    	x %= m;
    }

    vector<int> ans;
    // ans.push_back(x);
	reverse(all(s));

	for(auto c: s){
		if(c == 'L'){
			x *= a[--left];
			x %= m;
		} else {
			x *= a[++right];
			x %= m;
		}
		ans.push_back(x);
	}
	reverse(all(ans));
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