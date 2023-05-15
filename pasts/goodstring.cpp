
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
    int n;
    cin >> n;

    string s;
    cin >> s;
    // cout << s << "\n";
    int count = 0;
    string ans = "";
    int k = 0;
    for(int i = 0; i < n; i++){
    	if(k % 2 == 0){
    		if(s[i] == s[i + 1]){
    			count++;
    		}
    		else{
    			k++;
    			ans += s[i];
    		}
    	}
    	else{
    		ans += s[i];
    		k++;
    	}
    }
    if(ans.size() % 2 == 1){
    	ans = ans.substr(0, ans.size() - 1);
    	count++;
    }
    cout << count << "\n";
    cout << ans << "\n";
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