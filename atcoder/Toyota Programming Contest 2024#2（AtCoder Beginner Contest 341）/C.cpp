

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
    int h, w, n;
    cin >> h >> w >> n;
    string s;
    cin >> s;
    vector<string> g(h);
    for(int i = 0; i < h; i++){
    	cin >> g[i];
    }


    auto check = [&](int i, int j){
    	if(i < 0 || i >= h || j < 0 || j >= w || g[i][j] == '#')
    		return false;
    	return true;
    };

    function<bool(int,int,int)> dfs 
    = [&](int i, int j, int ind){
    	if(!check(i, j))
    		return false;

    	if(ind == n)
    		return true;

    	int ni = i, nj = j;
    	if(s[ind] == 'U')
    		ni -= 1;
    	if(s[ind] == 'D')
    		ni += 1;
    	if(s[ind] == 'R')
    		nj += 1;
    	if(s[ind] == 'L')
    		nj -= 1;

    	return dfs(ni, nj, ind + 1);
    };

    int count = 0;
    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++){
    		if(dfs(i, j, 0))
    			count += 1;
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