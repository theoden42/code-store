
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
    int f1 = 0, f2 = 0, f3 = 0;
    int j = 0;
    int mn = n + 1;

    for(int i = 0; i < n; i++){
    	while((f1 == 0 || f2 == 0 || f3 == 0) && j < n){
    		if(s[j] == '1'){
    			f1++;
    		}
    		if(s[j] == '2'){
    			f2++;
    		}
    		if(s[j] == '3'){
    			f3++;
    		}
    		j++;
    	}
    	if(f1 == 0 || f2 == 0 || f3 == 0){
    		break;
    	}
    	else{
    		mn = min(mn, j - i);
    	}
    	if(s[i] == '1'){
    		f1--;
    	}
    	else if(s[i] == '2'){
    		f2--;
    	}
    	else{
    		f3--;
    	}
    }

    if(mn == n + 1){
    	cout << 0 << "\n";
    }
    else{
    	cout << mn << "\n";
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