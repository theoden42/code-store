

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

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b) { 
	int n = a.size();
	int x = b.size();
	int m = b[0].size();
	vector<vector<int>> ans(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < x; k++){
				ans[i][j] += (a[i][k] * b[k][j]) % MOD;
				ans[i][j] %= MOD;
			}
		}
	}
	return ans;
}
 
vector<vector<int>> matexp(vector<vector<int>> a, int k){
	if(k == 1)
		return a;
	vector<vector<int>> v = matexp(a, k / 2);
	if(k & 1){
		return multiply(a, multiply(v, v));
	} else {
		return multiply(v, v);
	}
}

void solve() {
    int m, n;
    cin >> m >> n;
    vector<int> s(m ), l(m );
    for(int i = 0; i < m; i++)
    	cin >> s[i];
    for(int i = 0; i < m; i++)
    	cin >> l[i];

    vector<vector<int>> a(m, vector<int>(m));
    for(int i = 0; i < m; i++){
    	for(int j = 0; j < m; j++){
    		int ti = s[i] + l[i];
    		int tj = s[j] + l[j];
    		int t = ti * tj - l[i] * l[j];
    		t %= MOD;
    		a[i][j] = t;
    	}
    }


    vector<vector<int>> num = matexp(a, n);
    int ans = 0;
	for(int j = 0; j < m; j++){
		ans += num[0][j];
		ans %= MOD;
	}

    cout << ans << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}