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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mx = n + 1;
    for(int i = 0; i < n; i++){
    	if(s[i] == 'a'){
    		int b = 0;
    		int c = 0;
    		int j = i + 1;
    		for(j = i + 1; j < n; ++j){
    			if(s[j] == 'b')b++;
    			else if(s[j] == 'c')c++;
    			else break;
    		}
    		if(j == n)break;
    		if(b < 2 && c < 2)mx = min(mx, j - i + 1);
    		i = j - 1;
    	}
    }
    if(mx == n + 1){ 
    	debug(s);
	   	for(int i = 0; i < n; i++){
	    	if(s[i] == 'a'){
	    		int b = 0;
	    		int c = 0;
	    		int a = 1;
	    		int j = i + 1;

	    		while(j < n && a != 3){
	    			if(s[j] == 'a')a++;
	    			else if(s[j] == 'b')b++;
	    			else c++;
	    			j++;
	    		} 
	    		debug(i, j);
	    		if(a == 3 && b < a && c < a){
	    			debug(a, b, c);
	    			mx = min(mx, j - i);
	    		}
	    	}
    	} 
    	if(mx == n + 1)cout << "-1\n";
    	else cout << mx << "\n";
    }
    else{
    	cout << mx << "\n";
    }

   // abbabbabbaccaccacca
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