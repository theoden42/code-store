

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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> black;
    for(int i = 0; i < n; i++){
    	string st;
    	cin >> st;
    	for(int j = 0; j < m; j++){
    		if(st[j] == 'B'){
    			black.push_back({i, j});
    		}
    	}
    }

    int ansrow, anscol;
    cin >> ansrow >> anscol;

    if(black.size() == 0){
    	cout << 1 << " " << 1 << "\n";
    	return;
    }

    int ansmin = n + m;
    for(auto cell : black){
    	int dis = abs(ansrow - cell.first) + abs(anscol - cell.second);
    	ansmin = min(ansmin, dis);
    }

    int correctmin = n + m;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		int temp = 0;
    		for(auto cell : black){
    			int dis = abs(i - cell.first) + abs(j - cell.second);
    			temp = max(temp, dis);
    		}

    		correctmin = min(correctmin, temp);
    	}	
    }


    if(ansmin == correctmin){
    	cout << "Passed\n";
    }
    else{
    	cout << "Failed\n";
    	debug(black, correctmin, ansmin);
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