
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
    int n = s.size();
    int ind = -1;
    for(int i = 1; i < n - 1; ++i){
    	if(s[i] == 'a'){
    		ind = i;
    		break;
    	}
    }
    if(ind != -1){
    	cout << s.substr(0, ind) << " " << s[ind] << " " << s.substr(ind + 1, n - ind) << "\n";
    }
    else{
    	cout << s[0] << " " << s.substr(1, n - 2) << " " << s[n - 1] << "\n";
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