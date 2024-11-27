

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

vector<vector<int>> pk(MAX_N, vector<int>(32, -1));

void preprocess(){
	for(int i = 2; i < MAX_N; i++){
		pk[i][0] = 1;
		int val = 1;
		for(int j = 1; j < 32; j++){
			val = (val * i);

			if(val > MAX_N)
				break;

			pk[i][j] = val;	
		}
	}
}

void solve() {
	int n;
	cin >> n;

	for(int i = 2; i <= n; i++){
		int ind = 0;
		while(pk[i][ind] != -1){
			int x = pk[i][ind];
			int num = (x - 1) / (i - 1);
			if(num == n){
				cout << "YES\n";
				break;
			}
			ind++;
		}
	}

	cout << "NO\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
   	preprocess();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}