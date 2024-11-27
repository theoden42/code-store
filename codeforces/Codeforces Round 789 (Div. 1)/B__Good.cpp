

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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<vector<char>> grid(n, vector<char>(m, '0'));
    for(int i = 0; i < n * m; i++){
    	int row = 0;
    	int col = 0;
    	for(int j = i; j >= 0; j--){
    		grid[row][col] = s[j];
    		col += 1;
    		if(col == m){
    			col = 0;
    			row += 1;
    		}
    	}

    	set<int> cols, rows;
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m; j++){
    			if(grid[i][j] == '1'){
    				rows.insert(i);
    				cols.insert(j);
    			}
    		}
    	}

    	int ans = rows.size() + cols.size();
    	cout << ans << " ";
    }

    cout << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}