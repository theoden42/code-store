

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

    vector<vector<int>> a(3, vector<int>(3));
    for(int i = 0; i < 3; i++){
    	for(int j = 0; j < 3; j++){
    		cin >> a[i][j];
    	}
    }

    vector<vector<int>> col(3, vector<int>(3));

    auto check = [&](){	
    	for(int i = 0; i < 3; i++){
    		if(col[i][0] != 0 && col[i][1] == col[i][0] && col[i][2] == col[i][0])
    			return col[i][0];
    	}
    	for(int i = 0; i < 3; i++){
    		if(col[0][i] != 0 && col[1][i] == col[0][i] && col[2][i] == col[0][i])
    			return col[0][i];
    	}
    	if(col[0][0] != 0 && col[1][1] == col[0][0] && col[2][2] == col[0][0])
    		return col[0][0];
    	if(col[0][2] != 0 && col[1][1] == col[0][2] && col[2][0] == col[0][2])
    		return col[0][2];

    	return -1ll;
    };

    function<int(int, int, int)> dfs =
    [&](int mv, int sa, int sb){

    	int val = check();
    	if(val == 1)
    		return 0ll;
    	else if(val == 2)
    		return 1ll;

    	int flag = 0;
    	for(int i = 0; i < 3; i++){
    		for(int j = 0; j < 3; j++){
    			if(col[i][j] == 0){
    				flag = 1;
    				if(mv){
    					col[i][j] = 2;
    					int x = dfs(1 - mv, sa, sb + a[i][j]);
    					col[i][j] = 0;
    					if(x == mv){
    						return mv;
    					}
    				} else { 
    					col[i][j] = 1;
    					int x = dfs(1 - mv, sa + a[i][j], sb);
    					col[i][j] = 0;
    					if(x == mv){
    						return mv;
    					}
    				}
    			}
    		}
    	}

    	if(!flag){
    		return (int)(sb > sa);
    	}

    	return (1 - mv);
    };

    int ans = dfs(0, 0, 0);
    if(ans){
    	cout << "Aoki\n";
    } else {
    	cout << "Takahashi\n";
    }
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