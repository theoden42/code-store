
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
    if(n < 11){
    	cout << "NO" << "\n";
    	return;
    }
    int ind1 = -1;
    int ind2 = -1;
    for(int i = 0; i <= n - 1; i++){
    	if(s[i] == '5'){
   			if(ind1 == -1)
   				ind1 = i;
   			ind2 = i;
    	}
    }
    if(ind1 == -1 || ind2 == -1){
    	cout << "NO" << "\n";
    	return;
    }
    if(ind2 - ind1 >= 10){
    	cout << "YES" << "\n";
    }
    else
    	cout << "NO" << "\n";

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