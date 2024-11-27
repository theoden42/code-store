
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
    string q = "hello";
    int j = 0;
    int i = 0;
    for(i = 0; i <= 4 && j < n; i++){
    	while(j < n && s[j] != q[i])j++;
    	if(j == n){
    		cout << "NO" << "\n";
    		return;
    	}
    	j++;
    }
    if(i == 5){
    	cout << "YES" << "\n";
    }
    else{
    	cout << "NO" << "\n";
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