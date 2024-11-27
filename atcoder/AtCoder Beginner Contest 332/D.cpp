

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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w, 0)), b(h, vector<int>(w, 0));
    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++){
    		cin >> a[i][j];
    	}
    }
    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++){
    		cin >> b[i][j];
    	}
    }
    vector<int> rows, cols;
    for(int i = 1; i <= h; i++){
    	rows.push_back(i);
    }
    for(int i = 1; i <= w; i++){
    	cols.push_back(i);
    }


    vector<vector<int>> rowperm, colperm;
    do{
    	rowperm.push_back(rows);
    } while(next_permutation(all(rows)));

    do{
    	colperm.push_back(cols);
    } while(next_permutation(all(cols)));


    auto countop = [&](vector<int>& v){
    	int ans = 0;
    	for(int i = 0; i < v.size(); i++){
    		for(int j = i + 1; j < v.size(); j++){
    			if(v[j] < v[i])
    				ans += 1;
    		}
    	}

    	return ans;
    };


    int mnans = 1e9;
    for(auto& rp: rowperm){
    	for(auto& cp: colperm) { 
    		int f = 1;
    		for(int i = 0; i < h; i++){
    			for(int j = 0; j < w; j++){
    				if(a[rp[i] - 1][cp[j] - 1] != b[i][j]){
    					f = 0;
    					break;
    				}
    			}
    		}
    		if(f){
    			// debug(rp, cp);
    			int a1 = countop(rp);
    			int a2 = countop(cp);
    			mnans = min(mnans, a1 + a2);
    		}
    	}
    }

    if(mnans == 1e9)
        mnans = -1;

    cout << mnans << "\n";
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