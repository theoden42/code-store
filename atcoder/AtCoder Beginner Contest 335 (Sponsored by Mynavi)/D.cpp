

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
	vector<vector<int>> v(n, vector<int>(n, -1));
	int row = 0;
	int col = 0;
	char dir = 'R';

	int minrow = 0;
	int maxrow = n - 1;
	int mincol = 0;
	int maxcol = n - 1;

	for(int count = 1; count <= n * n - 1; count += 1){
		v[row][col] = count;
		if(dir == 'R')
			col += 1;
		else if(dir == 'L')
			col -= 1;
		else if(dir == 'U')
			row -= 1;
		else if(dir == 'D')
			row += 1;

		if(row < minrow){
			dir = 'R';
			mincol += 1;
			row += 1;
			col += 1;
		} 
		if(row > maxrow){
			dir = 'L';
			row -= 1;
			col -= 1;
			maxcol -= 1;
		}
		if(col > maxcol){
			dir = 'D';
			col -= 1;
			row += 1;
			minrow += 1;
		}
		if(col < mincol){
			dir = 'U';
			col += 1;
			row -= 1;
			maxrow -= 1;
		}
		// debug(row, col);
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(v[i][j] == -1){
				cout << "T ";
			} else {
				cout << v[i][j] << " ";
			}
		}
		cout << "\n";
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