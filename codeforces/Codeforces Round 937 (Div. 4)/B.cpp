

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
    vector<vector<char>> g(2 * n, vector<char>(2 * n));
    int count = 0;
    for(int i = 0; i < 2 * n; i += 2){
    	if((i / 2) & 1)
    		count = 1;
    	else 
    		count = 0;

    	for(int j = 0; j < 2 * n; j += 2){
    		char ch = (char)((count & 1) ? '.': '#');
    		g[i][j] = ch;
    		g[i][j + 1] = ch;
    		g[i + 1][j] = ch;
    		g[i + 1][j + 1] = ch;

    		count = 1 - count;
    	}
    }

    for(int i = 0; i < 2 * n; i++){
    	for(int j = 0; j < 2 * n; j++){
    		cout << g[i][j];
    	}
    	cout << "\n";
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