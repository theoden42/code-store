
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
    int n, m;
    cin >> n >> m;
    int c1 = 0;
    int c2 = 0;

    int temp = n;
    while(n % 2 == 0){
    	c1++;
    	n /= 2;
    }
    while(n % 5 == 0){
    	c2++;
    	n /= 5;
    }


    ll ans = 1;

    if(c1 > c2){
    	 int t = c1 - c2;
    	 while(t > 0 && ans * 5 <= m){
    		t--;
    		ans *= 5;
    	}
    }
    else{
    	int t = c2 - c1;
    	while(t > 0 && ans * 2 <= m){
    		t--;
    		ans *= 2;
    	}
    }



    while(ans * 10 <= m){
    	ans *= 10;
    }

    for(int i = 9; i >= 1; i--){
    	if(ans * i <= m)ans *= i;
    }

    cout << 1ll * temp * ans << '\n';


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