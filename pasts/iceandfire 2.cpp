
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
    int l0 = -1;
    int l1 = -1;

    int in = 1;


    for(int i = 2; i <= n; i++){
    	int ind = i - 2;

    	if(s[ind] == '1'){
    		// we must have a lower number win so atleast one zero must be there so that the lower number can win the round and proceed 
    		if(l0 == -1){
    			// no greater can be eliminate
    			cout << 1 << " ";
    		}
    		else{
    			cout << 1 + l0 << " "; 
    		}
    		l1 = ind + 1;
    	}
    	else{
    		if(l1 == -1){
    			cout << 1 << " ";
    		}
    		else{
    			cout << l1 + 1 << " ";
    		}
    		l0 = ind + 1;
    	}
    }
    cout << "\n";

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