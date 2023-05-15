
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
    map<string,int> mp;
    for(int i = 0; i < n - 1; i++){
    	string temp = ""; 
    	temp += s[i];
    	temp += s[i + 1];

   		if(i != 0 && s[i - 1] == s[i] && s[i + 1] == s[i]){
    		if(mp[temp] >= 2){
    			cout << "YES\n";
    			return;
    		}
    	}
    	else{
    		if(mp[temp] >= 1){
    			debug(temp, mp[temp]);	
    			cout << "YES\n";
    			return;
    		}
    	}

    	mp[temp] += 1;
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