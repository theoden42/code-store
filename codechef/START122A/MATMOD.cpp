

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

vector<int> factorial(MAX_N + 1, 1);
void pre(){
	for(int i = 1; i <= MAX_N; i++){
		factorial[i] = (i * factorial[i - 1]) % MOD;
	}
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		cin >> a[i][j];
    	}
    }	

    int lb = 1;
    int ub = n * n;
    int k = 0;
    while(lb <= ub){
    	int mid = lb + (ub - lb) / 2;
    	int count = 0;
    	for(int j = 0; j < mid; j++){
            int num;
            if(j == 0)
                num = (n * n - j) / mid;
            else 
                num = (n * n - j) / mid + 1;

    		count += num / 2;
    	}
    	if(count >= (n * n - n) / 2){
    		k = mid;
    		lb = mid + 1;
    	} else {
    		ub = mid - 1;
    	}
    }

    set<int> st;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            st.insert(a[i][j]);
        }
    }

    vector<int> f(k);

    for(int i = 1; i <= n * n; i++){
        if(st.find(i) == st.end()){
           debug(i % k);
    	   f[i % k] += 1;
        }
    }

    int ans = 1;
    int other = 0;
    int single = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < i; j++){
    		if(a[i][j] == 0 && a[j][i] == 0){
    			other += 1;
    		} else if(a[i][j] != 0) {
    			ans *= f[a[i][j] % k];
    			ans %= MOD;
    			f[a[i][j] % k] -= 1;
    		} else {
    			ans *= f[a[j][i] % k];
    			ans %= MOD;
    			f[a[j][i] % k] -= 1;
    		}
    	}
    }


    for(int i = 0; i < n; i++){
    	if(a[i][i] == 0)
    		single += 1;
    }

    int filled = 0; 
    int pairform = 1;
    for(int i = 0; i < k; i++){
    	if(f[i] & 1){
    		ans *= f[i];
    		ans %= MOD;
            filled += 1;
    		single -= 1;
    	}

        pairform *= factorial[f[i] / 2];
        pairform %= MOD;
        if(f[i] >= 2){
            pairform *= 2;
            pairform %= MOD;
        }
    }


    ans *= pairform;
    ans %= MOD;
    ans *= factorial[filled];
    ans %= MOD;

    if(single < 0 || single & 1){
    	cout << "0\n";
    	return;
    }

    int pr = (single * (single - 1)) / 2;
    debug(ans);
    pr %= MOD;
    int total = other + single / 2;
    ans *= factorial[total];
    ans %= MOD;
    ans %= pr;
    ans %= MOD;


    cout << ans << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    pre();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}