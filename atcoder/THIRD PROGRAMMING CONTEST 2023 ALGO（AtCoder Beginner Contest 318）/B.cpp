

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
    vector<vector<int>> grid(150, vector<int>(150, 0));
   	vector<vector<int>> c(n);
   	for(int i = 0; i < n; i++){
   		int a, b, x, d;
   		cin >> a >> b >> x >> d;
   		c[i] = {a, b, x, d};
   	}
   	sort(all(c));

   	for(int i = 0; i < n; i++){
   		for(int col = c[i][0]; col < c[i][1]; col++){
   			for(int row = c[i][2]; row < c[i][3]; row++){
   				grid[row][col] = 1;
   			}
   		}
   	}

   	int count = 0;
   	for(int i = 0; i < 150; i++){
   		for(int j = 0; j < 150; j++){
   			if(grid[i][j])
   				count++;
   		}
   	}
   	cout << count << "\n";
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