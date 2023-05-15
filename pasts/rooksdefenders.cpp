
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> rows(n);
    vector<int> cols(n);

    set<int> zeroscols;
    set<int> zerosrows;

    for(int i = 0; i < n; i++){
    	zeroscols.insert(i);
    	zerosrows.insert(i);
    }


    for(int i = 1; i <= q; i++){
    	debug(zeroscols, zerosrows);
    	int t;
    	cin >> t;
    	if(t == 1){
    		int x, y;
    		cin >> x >> y;

    		if(rows[x - 1] == 0){
    			zerosrows.erase(x - 1);
    		}
    		rows[x - 1]++;

    		if(cols[y - 1] == 0){
    			zeroscols.erase(y - 1);
    		}
    		cols[y - 1]++;
    	}
    	else if(t == 2){
    		int x, y;
    		cin >> x >> y;
    		rows[x - 1]--;
    		if(rows[x - 1] == 0){
    			zerosrows.insert(x - 1);
    		}
    		cols[y - 1]--;
    		if(cols[y - 1] == 0){
    			zeroscols.insert(y - 1);
    		}
    	}
    	else{
    		int x1, y1, x2, y2;
    		cin >> x1 >> y1 >> x2 >> y2;
    		//(all are positive between x1 and x2 or vice versa for the columns y1 and y2)

    		if(zerosrows.lower_bound(x1 - 1) == zerosrows.end()){
    			cout << "YES\n";
    			continue;

    		}
    		if(zeroscols.lower_bound(y1 - 1) == zeroscols.end()){
    			cout << "YES\n";
    			continue;
    		}

    		int xf = *zerosrows.lower_bound(x1 - 1);
    		int yf = *zeroscols.lower_bound(y1 - 1);

    		if(xf >= x2 || yf >= y2){
    			cout << "YES\n";
    		}
    		else{
    			cout << "NO\n";
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