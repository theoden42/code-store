

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
    int n;
    cin >> n;
    vector<vector<int>> ran(3, vector<int>(n + 1));
    vector<vector<int>> pos(3, vector<int>(n + 1));
    for(int i = 0; i < 3; i++){
    	for(int j = 1; j <= n; j++){
    		int x;
    		cin >> x;
    		x = n + 1 - x;
    		ran[i][j] = x;
    		pos[i][x] = j;
    	}
    };

    vector<ordset<int>> segs(3);
    for(int i = 0; i < 3; i++){
    	segs[i].insert(ran[i][n]);
    }
    vector<int> dp(n + 1);
    vector<pair<int,int>> moves(n + 1);
    dp[n] = 1;
    for(int i = n - 1; i >= 1; i--){
    	for(int j = 0; j < 3; j++){
    		int rank = rank[j][i]; 
    		auto it = segs[j].upper_bound(rank);
    		if(it != segs[j].end()){
    			int card_val = pos[j][*it];
    			dp[i] = 1;
    			for(int k = 0; k < 3; k++){
    				segs[k].insert(ran[k][i]);
    			}
    			moves[i] = {j, card_val};
    			break;
    		}
    	}
    }

    if(!dp[1]){
    	cout << "NO\n";
    	return;
    }
    cout << "YES\n";
    int cd = 1;
    int count = 0;
    vector<string> ans;
    while(cd != n){
    	auto [j, v] = moves[cd];
    	if(j == 0){
    		ans.push_back("q " + to_string(v));
    	} else if(j == 1){
    		ans.push_back("k " + to_string(v));
    	} else {
    		ans.push_back("j " + to_string(v));
    	}
    	cd = v;
    }
    cout << ans.size() << "\n";
    for(auto s: ans){
    	cout << s << "\n";
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