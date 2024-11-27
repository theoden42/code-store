

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

vector<int> dp(1e5 + 1);

int check(int n){
	int t = n;
	while(t != 0){
		int x = t % 10;
		if(x != 0 && x != 1)
			return 0;
		t /= 10;
	}
	return 1;
}

void pre(){
	for(int i = 1; i <= 1e5; i++){
		if(check(i)){
			dp[i] = 1;
			continue;
		}
		for(int j = 1; j * j <= i; j++){
			if(i % j == 0){
				if(dp[i / j] && dp[j]){
					dp[i] = 1;
					break;
				}
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;
	if(dp[n]){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}


int main() {
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