
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
    int cw = 0, cb = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == 'B')cb++;
    	else cw++;
    }

    if(cb == 0){
    	cout << 0 << "\n";
    	return;
    }
    if(cw == 0){
    	cout << -1 << "\n";
    	return;
    }

    if(s.back() == 'W'){
    	cout << cb << "\n";
    	return;
    }
    else{
    	int ind = -1;
    	for(int i = n - 1; i >= 0; i--){
    		if(s[i] == 'W'){
    			ind = i;
    			break;
    		}
    	}

    	int ans = cb + (n - 1 - ind);
    	cout << ans << "\n";
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