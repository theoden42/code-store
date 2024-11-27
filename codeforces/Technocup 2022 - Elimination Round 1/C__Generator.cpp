

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
   int n = 1 + rng() % 10;
   int m = 1 + rng() % 10;
   cout << n << " " << m << "\n";
   vector<vector<char>> grid(n, vector<char>(m));
   for(int i = 0; i < n; i++){
   	for(int j = 0; j < m; j++){
   		if(rng() % 2 == 0){
   			grid[i][j] = 'X';
   		} else {
   			grid[i][j] = '.';
   		}
   	}
   }
   for(int i = 0; i < n; i++){
   	for(int j = 0; j < m; j++){
   		cout << grid[i][j];
   	}
   	cout << "\n";
   }
   int q = 5 + rng() % 10;
   cout << q << "\n";
   for(int i = 0; i < q; i++){
   	int l = rng() % m + 1;
   	int r = rng() % m + 1;
   	cout << min(l, r) << " " << max(l, r) << "\n";
   }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}