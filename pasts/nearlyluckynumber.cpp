
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
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < s.size(); i++){
    	if(s[i] == '4' || s[i] == '7')count++;
    }
    if(count == 0){
    	cout << "NO\n";
    	return;	
    }
    while(count != 0){
    	int r = count % 10;
  		if(r != 4 && r != 7){
  			cout << "NO\n";
  			return;
  		}
  		count /= 10;
    }
    cout << "YES\n";
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