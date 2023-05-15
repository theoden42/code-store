
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
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int d, k;
    cin >> d >> k;
    if(d < k){
    	cout << "Utkarsh\n";
    	return;
    }
    else{
    	int x = 1;

    	while(1){
    		ll val = 0;
    		if(x % 2 == 1){
    			ll temp = 1ll * ((x - 1) / 2) * k;
    			val += (temp * temp);
    			temp = ((x - 1) / 2 + 1) * k;
    			val += temp * temp;
    		}
    		else{
    			ll temp = 1ll * ((x) / 2) * k;
    			val += 2 * temp * temp;
    		}

    		if(val > 1ll * d * d){
    			break;
    		}
    		else{
    			x++;
    		}
    	}


    	debug(x);
    	if(x % 2 != 0){
    		cout << "Utkarsh\n";
    	}	
    	else{
    		cout << "Ashish\n";
    	}
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}