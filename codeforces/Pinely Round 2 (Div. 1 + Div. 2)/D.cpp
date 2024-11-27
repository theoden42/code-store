

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
    vector<string> g(n);
    for(int i = 0; i < n; i++){
    	cin >> g[i];
    }
    vector<vector<char>> ans(n, vector<char>(m, '.'));

    for(int j = 0; j < m; j++){
    	int count = 0;
    	for(int i = 0; i < n; i++){
    		if(g[i][j] == 'L')
    			count++;
    	}

		if(count & 1){
			cout << "-1\n";
			return;
		}
		int currcount = 0;
		for(int i = 0; i < n; i++){
			if(g[i][j] == 'L'){
				if(currcount < count / 2){
					ans[i][j] = 'W';
					ans[i][j + 1] = 'B';
				} else {
					ans[i][j] = 'B';
					ans[i][j + 1] = 'W';
				}
				currcount += 1;
			}
		}
    }

    for(int i = 0; i < n; i++){
    	int count = 0;
    	for(int j = 0; j < m; j++){
    		if(g[i][j] == 'U'){
    			count++;
    		}
    	}

    	if(count & 1){
    		cout << "-1\n";
    		return;
    	}
    	int curcount = 0;
    	for(int j = 0; j < m; j++){
    		if(g[i][j] != 'U')
    			continue;
    		if(curcount < count / 2){
    			ans[i][j] = 'W';
    			ans[i + 1][j] = 'B';
    		} else {
    			ans[i][j] = 'B';
    			ans[i + 1][j] = 'W';
    		}
    		curcount += 1;
    	}
    }

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cout << ans[i][j];
    	}
    	cout << "\n";
    }

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