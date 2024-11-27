

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
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> pos;
    // pos.push_back({1, 0});
    int headx = 1;
    int heady = 0;
    for(int i = 1; i <= q; i++){
    	int t;
    	cin >> t;
    	if(t == 1){
    		char c;
    		cin >> c;
    		if(c == 'U'){
    			heady += 1;
    		} else if(c == 'L'){
    			headx -= 1;
    		} else if(c == 'R'){
    			headx += 1;
    		} else {
    			heady -= 1;
    		}
			pos.push_back({headx, heady});
    	} else {
    		int p;
    		cin >> p;
    		if(p > pos.size()){
    			int temp = p - pos.size();
    			cout << temp << " " << 0 << "\n";
    		} else {
    			auto [x, y] = pos[pos.size() - p];
    			cout << x << " " << y << "\n";
    		}
    	}
    }

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