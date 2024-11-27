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

vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) { 
	int n = a.size();
	int x = b.size();
	int m = b[0].size();
	vector<vector<int>> ans(n, vector<int>(m, 2e18));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < x; k++) if(k != i && k != j){
				ans[i][j] = min(ans[i][j], (a[i][k] + b[k][j]));
			}
		}
	}
	return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> vals(n, vector<int>(n));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		cin >> vals[i][j];
    	}
    }

    vector<vector<int>> dis(all(vals));
    for(int k = 0; k < n; k++){
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < n; j++){
    			dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    		}
    	}
    }

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(dis[i][j] < vals[i][j]){
    			cout << "-1\n";
    			return;
    		}
    	}
    }

    vector<vector<int>> temp(all(vals));
    vector<vector<int>> v(n, vector<int>(n));
	temp = multiply(temp, vals);
	for(int j = 0; j < n; j++){
		for(int k = 0; k < n; k++) if(j != k){
			if(temp[j][k] == vals[j][k]) {
				v[j][k] = v[k][j] = 1;
			}
		}
	}

    int count = 0;
   	for(int i = 0; i < n; i++){
   		for(int j = i + 1; j < n; j++){
   			if(v[i][j] == 1)
   				count += 1;
   		}
   	}

   	cout << count << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}