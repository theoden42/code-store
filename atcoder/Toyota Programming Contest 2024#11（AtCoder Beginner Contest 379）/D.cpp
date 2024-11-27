

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
    int q;
    cin >> q;
    queue<int> trees;
    int curr_time = 0;	
    for(int i = 0; i < q; i++){
    	int t;
    	cin >> t;
    	if(t == 1){
    		trees.push(curr_time);
    	} else if (t == 2){
    		int T;
    		cin >> T;
    		curr_time += T;
            // debug(curr_time);
    	} else if(t == 3) {
    		int count = 0;
    		int H;
    		cin >> H;
            // debug(H, curr_time, trees.front());
    		while(!trees.empty() 
                && trees.front() <= curr_time - H){
    			count += 1;
    			trees.pop();
    		}
    		cout << count << "\n";
    	}
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