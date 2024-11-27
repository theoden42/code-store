

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
    int n, q;
    cin >> n >> q;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    }
    vector<string> mp = {"BG", "BR", "BY", "GR", "GY", "RY"};
    vector<vector<int>> last(n, vector<int>(6, -1)), first(n, vector<int>(6, -1));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < 6; j++){
    		if(i != 0){
    			last[i][j] = last[i - 1][j];
    		}
    		if(mp[j] == v[i]){
    			last[i][j] = i;
    		}
    	}
    }
    for(int i = n - 1; i >= 0; i--){
    	for(int j = 0; j < 6; j++){
    		if(i != n - 1){
    			first[i][j] = first[i + 1][j];
    		}
    		if(mp[j] == v[i]){
    			first[i][j] = i; 
    		}
    	}
    }
    for(int i = 0; i < q; i++){
    	int x, y;
    	cin >> x >> y;
    	x -= 1;
    	y -= 1;
    	if(y < x)
    		swap(x, y);
    	int f = 0;
    	for(int j = 0; j < 2; j++){
    		for(int k = 0; k < 2; k++){
    			if(v[x][j] == v[y][k])
    				f = 1;
    		}
    	}
    	if(f){
    		int ans = y - x;
    		cout << ans << "\n";
    		continue;
    	}
    	int ans = 1e18;
    	for(int j = 0; j < 6; j++){
    		if(mp[j] != v[x] && mp[j] != v[y]){
    			if(last[y][j] > x){
    				ans = min(ans, y - x);
    				continue;
    			} 
    			if(last[x][j] != -1){
    				ans = min(ans, y - x + 2 * abs(x - last[x][j]));
    			}
    			if(first[y][j] != -1){
    				ans = min(ans, y - x + 2 * abs(first[y][j] - y));
    			}
    		}
    	}
	   	if(ans == 1e18){
			cout << "-1\n";
		} else {
			cout << ans << "\n";
		}
    }
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}