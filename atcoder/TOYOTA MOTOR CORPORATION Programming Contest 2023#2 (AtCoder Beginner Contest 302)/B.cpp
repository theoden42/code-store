

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

vector<pair<int,int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> st(n);
    for(int i = 0; i < n; i++){
    	cin >> st[i];
    }

    auto bounded = [&](int x, int y){
    	return (x >= 0 && x < n && y >= 0 && y < m);
    };

    auto check = [&](int i, int j){	
    	string word = "snuke";

    	for(auto d: dir){
    		int count = 0;
	    	int x = i;
	    	int y = j;
	    	vector<pair<int,int>> ans;
	    	for(count < 0; count < 5; count++){
	    		// debug(x, y, st[x][y], word[count]);
	    		if(bounded(x, y) && st[x][y] == word[count]){
	    			ans.push_back({x, y});
	    			x += d.first;
	    			y += d.second;
	    		}
	    		else{
	    			break;
	    		}
	    	}
	    	if(count == 5){
	    		for(auto& p: ans){
	    			cout << p.first + 1 << " " << p.second  << "\n";
	    		}
	    		return true;
	    	}
	    	ans.clear();
    	}
    	return false;
    };

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(st[i][j] == 's'){
    			debug(i, j);
    			if(check(i, j)){
    				return;
    			}
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