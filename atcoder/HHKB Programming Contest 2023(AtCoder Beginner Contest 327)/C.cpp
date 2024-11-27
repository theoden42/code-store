

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
	int n = 9, m = 9;
    vector<vector<int>> v(9, vector<int>(9, 0));
    for(int i = 0; i < 9; i++){
    	for(int j = 0; j < 9; j++){
    		cin >> v[i][j];
    	}
    }
    for(int i = 0; i < n; i++){
    	set<int> st;
    	for(int j = 0; j < m; j++){
    		st.insert(v[i][j]);
    	}
    	if(st.size() != 9){
    		cout << "No\n";
    		return;
    	}
    }
    for(int j = 0; j < n; j++){
    	set<int> st;
    	for(int i = 0; i < n; i++){
    		st.insert(v[i][j]);
    	}
    	if(st.size() != 9){
    		cout << "No\n";
    		return;
    	}
    }

    for(int i = 0; i < 9; i += 3){
    	for(int j = 0; j < 9; j += 3){
    		set<int> st;
    		for(int k = i; k < i + 3; k++){
    			for(int l = j; l < j + 3; l++){
    				st.insert(v[k][l]);
    			}
    		}
    		if(st.size() != 9){
    			cout << "No\n";
    			return;
    		}
    	}
    }

    cout << "Yes\n";

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