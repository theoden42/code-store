
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
    int ans = n - 1;

    for(int i = 0; i < n - 2; i++){
    	if(s[i] != s[i + 2])continue;
    	int j = i;
    	while(j < n - 2){
    		if(s[j] == s[j + 2]){
    			j++;
    		}
    		else{
    			break;
    		}
    	}
    	ans -= j - i;
    	i = j - 1;
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