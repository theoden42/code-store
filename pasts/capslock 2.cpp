
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int flag = 1;
    for(int i = 1; i < n; i++){
    	if( 'A' <= s[i] && s[i] <= 'Z'){
    		continue;
    	}
    	else{
    		flag = 0;
    	}
    }
    if(flag == 0){
    	cout << s << "\n";
    }
    else{
    	string ans = "";
    	for(int i = 0; i < n; i++){
    		if( 'A' <= s[i] && s[i] <= 'Z'){
    			ans += (char)('a' + (s[i] - 'A'));
    		}
    		else{
    			ans += (char)('A' + (s[i] - 'a'));
    		}
    	}
    	cout << ans << "\n";
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