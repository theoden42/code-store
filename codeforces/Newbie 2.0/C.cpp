
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
    int x = 0;
    int n = s.size();

    for(int i = 0; i < n; i++){
    	if(s[i] == 'a' && x != 0){
    		break;
    	}
    	else if(s[i] == 'a')continue;
    	else{
    		s[i] = s[i] - 1;
    		x++;
    	}
    }

    if(x == 0){
    	s[n - 1] = 'z';
    }

    cout << s << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}