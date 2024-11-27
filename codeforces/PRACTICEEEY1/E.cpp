

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
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];		
	}

	vector<int> dp(2e5 + 1), ndp(2e5 + 1);

	dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 2e5; j++){
			ndp[j] = 0;
		}
		for(int j= 0; j <= 2e5; j++){
			if(j + a[i] <= 2e5){
				ndp[j + a[i]] |= dp[j];
			}
			ndp[j] |= dp[j];	
		}
		dp = ndp;
	}
	if(sum & 1 || !dp[sum / 2]){
		cout << 0 << "\n";
	} else {
		cout << 1 << "\n";	
		while(true){
			vector<int> temp;
			for(int i = 0; i < n; i++){
				if(a[i] & 1){
					cout << i + 1 << "\n";
					return;
				}
				else{
					temp.push_back(a[i] / 2);
				}
			}
			a = temp;
		}
	}

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