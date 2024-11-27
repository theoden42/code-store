

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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> v(h);
    for(int i = 0; i < h; i++)
    	cin >> v[i];
    int count = 0;
    vector<vector<int>> vis(h, vector<int>(w));
    auto check = [&](int i, int j){
    	return (i < h && i >= 0 
    		&& j < w && j >= 0 
    		&& !vis[i][j] && v[i][j] == '.');
    };
    function<int(int,int,int)> start 
    = [&](int i, int j, int t){
    	vis[i][j] = 1;
    	if(t == k){
    		vis[i][j] = 0;	
    		return 1;
    	}
    	int val = 0;
    	if(check(i - 1, j)){
    		val += start(i - 1, j, t + 1);
    	}
    	if(check(i + 1, j)){
    		val += start(i + 1, j, t + 1);
    	}
    	if(check(i, j - 1)){
    		val += start(i, j - 1, t + 1);
    	}
    	if(check(i, j + 1)){
    		val += start(i, j + 1, t + 1);
    	}
    	vis[i][j] = 0;
    	return val;
    };
    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++) if(v[i][j] != '#'){
    		count += start(i, j, 0);
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