

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

int gsum(int l, int r){
	int sum = (r * (r - 1)) / 2;
	sum -= (l * (l - 1)) / 2;
	return sum;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int lb = (n * (n - 1)) / 2;
    int ub =  (n - 1) * (n - 1);
    if(k < lb || k > ub){
    	cout << "-1\n";
    	return;
    }

    int extra = k - lb;
    int ind = 1;
    for(int i = 2; i <= n; i++){
    	int gen = (i - 1);
    	if(gen <= extra){
    		extra -= gen;
    		ind = i;
    	}
    	else 
    		break;
    }

    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++){
    	ans[i] = i;
    }
    if(ind != 1){
    	swap(ans[2], ans[ind + 1]);
    	if(ind + 2 <= n)
    		swap(ans[ind + 2 - extra], ans[ind + 2]);
    }

    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " \n"[i == n];
    }

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