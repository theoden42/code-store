
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
    int r = 0;
    int c = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
    	if(s[i] == 'L'){
    		c -= 1;
    	}
    	else if(s[i] == 'R'){
    		c += 1;
    	}
    	else if(s[i] == 'U'){
    		r += 1;
    	}
    	else{
    		r -= 1;
    	}
    	if(r == 1 && c == 1){
    		cout << "YES\n";
    		return;
    	}
    }
    cout << "NO\n";
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