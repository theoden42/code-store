

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
    vector<int> b(n);
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }
    if(n == 1){
    	cout << "YES\n";
    	cout << b[0] << "\n";
    	return;
    }

    int sum = accumulate(all(b), 0ll);
   	int div = (n * (n + 1)) / 2;
   	if(sum % div != 0){
   		cout << "NO\n";
   		return ;
   	}

   	sum /= div;

   	vector<int> diff(n);
   	for(int i = 0; i < n; i++){
   		diff[(i + 1) % n] = b[(i + 1) % n] - b[i];
   	}
   	vector<int> ans(n);
   	for(int i = 0; i < n; i++){

   		ans[i] = (sum - diff[i]);
   		if(ans[i] <= 0 || ans[i] % n != 0){
   			cout << "NO\n";
   			return;
   		}
   		ans[i] /= n;
   	}

   	cout << "YES\n";
   	for(int i = 0; i < n; i++){
   		cout << ans[i] << " ";
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