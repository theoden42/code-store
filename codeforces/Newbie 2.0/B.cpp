
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
    if(n >= 3){
    	cout << "NO\n";
    	return;
    }
    if(n == 1){
    	cout << "YES\n";
    	return;
    }
    if(s == "11" || s == "00"){
    	cout << "NO\n";
    }
    else{
    	cout << "YES\n";
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