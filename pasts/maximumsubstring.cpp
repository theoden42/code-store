
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
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == '0')x++;
    	else y++;
    }
    int mx = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == '1'){
    		if(i == 0 || s[i - 1] == '0'){
    			count = 1;
    		}
    		else{
    			count++;
    		}
    	}
    	else{
    		mx = max(count, mx);
    		count = 0;
    	}
    }
    mx = max(mx, count);

    int mx2 = 0;
    count = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == '0'){
    		if(i == 0 || s[i - 1] == '1'){
    			count = 1;
    		}
    		else{
    			count++;
    		}
    	}
    	else{
    		mx2 = max(mx2, count);
    		count = 0;
    	}
    }
    mx2 = max(mx2, count);

    ll ans1 = 1ll * mx * mx;
    ll ans2 = 1ll * mx2 * mx2;
    ll ans3 = 1ll * x * y;
    cout << max({ans1, ans2, ans3}) << "\n";

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