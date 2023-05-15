
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
    int m = 0;
    string ans = "";
    int ind = n - 1;
    for(int i = 0; i < n - 1; i++){
    	if(s[i] - '0' > s[i + 1] - '0'){
    		ind = i;
    		m = s[i] - '0';
    		break;
    	}
    }
    int flag = 0;
    for(int i = 0; i < n; i++){
    	if(i == ind)
    		continue;
    	else{
    		if(flag == 0 && s[i] == '0')
    			continue;
    		else if(flag == 0 && s[i] != '0'){
    			ans += s[i];
    			flag = 1;
    		}
    		else{
    			ans += s[i];
    		}
    	}
    }
    cout << ans << "\n";
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