
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
    int one = 0;
    int zero = 0;
    int n, q;
    cin >> n >> q;
    vector<int> val(n);
    for(int i = 0; i < n; i++){
    	cin >> val[i];
    	if(val[i] & 1)one++;
    	else zero++;
    }
    for(int i = 1; i <= q; i++){
    	int t;
    	cin >> t;
    	if(t == 1){
    		int x;
    		cin >> x;
    		x--;
    		if(val[x] == 0){
    			val[x] = 1;
    			zero--;
    			one++;
    		}
    		else{
    			val[x] = 0;
    			one--;
    			zero++;
    		}
    	}
    	else{
    		int k;
    		cin >> k;
    		if(one >= k){
    			cout << 1 << "\n";
    		}
    		else{
    			cout << 0 << "\n";
    		}
    	}
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