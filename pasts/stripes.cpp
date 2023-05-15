
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

	    vector<vector<char>> grid(8, vector<char>(8));


	    for(int i = 0; i < 8; i++){
	    	string s;
	    	cin >> s;
	    	for(int j = 0; j < 8; j++){
	    		grid[i][j] = s[j];
	    	}
	    }

	    for(int i = 0; i < 8; i++){
	    	int f = 1;
	    	for(int j = 0; j < 8; j++){
	    		if(grid[i][j] == 'R')
	    			continue;
	    		else{
	    			f = 0;
	    			break;
	    		}
	    	}
	    	if(f){
	    		cout << "R" << "\n";
	    		return;
	    	}
	    }
	    cout << "B" << "\n";
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