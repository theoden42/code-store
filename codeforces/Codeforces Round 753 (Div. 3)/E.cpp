

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
    string s;
    cin >> s;
    int left = 0;
    int right = m - 1;
    int up = 0;
    int down = n - 1;

    int mncol = 0;
    int mxcol = 0;
    int mnrow = 0;
    int mxrow = 0;
    int row = 0;
    int col = 0;
    for(int i = 0; i < s.size(); i++){
    	if(s[i] == 'L')
    		col--;
    	else if(s[i] == 'R')
    		col++;
    	else if(s[i] == 'U')
    		row--;
    	else 
    		row++;
    	mxrow = max(mxrow, row);
    	mnrow = min(mnrow, row);
    	mxcol = max(mxcol, col);
    	mncol = min(mncol, col);

    	int nleft = max(left, -mncol);
    	int nright = min(right, m - 1 - mxcol);
    	int nup = max(up, -mnrow);
    	int ndown = min(down, n - 1 - mxrow);

    	if(nleft > nright || nup > ndown){
    		break;
    	} 
    	left = nleft;
    	right = nright;
    	up = nup;
    	down = ndown;
    }
    for(int i = up; i <= down; i++){
    	for(int j = left; j <= right; j++){
    		cout << i + 1 << " " << j + 1 << "\n";
    		return;
    	}
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