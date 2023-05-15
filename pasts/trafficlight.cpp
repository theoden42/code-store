
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
    char c;
    cin >> c;
    string s;
    cin >> s;
    int fg = -1;
    for(int i = 0; i < n; i++){
    	if(s[i] == 'g'){
    		fg = i;
    		break;
    	}
    }
    vector<int> nextg(n, 0);

    if(s[n - 1] == 'g'){
    	nextg[n - 1] = n - 1;
    }
    else{
    	nextg[n - 1] = fg;
    }
    
    for(int i = n - 2; i >= 0; i--){
    	if(s[i] == 'g'){
    		nextg[i] = i;
    	}
    	else{
    		nextg[i] = nextg[i + 1];
    	}

    }
    if(c == 'g'){
    	cout << "0\n";
    }
    else{
    	int mx = 0;
    	for(int i = 0; i < n; i++){
    		if(s[i] == c){
    			int y = nextg[i];
    			if(y > i){
    				mx = max(y - i, mx);
    			}
    			else{
    				mx = max(mx, n + y - i);
    			}
    		}
    	}
    	cout << mx << "\n";
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