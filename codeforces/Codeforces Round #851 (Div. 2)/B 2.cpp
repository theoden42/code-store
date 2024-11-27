
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

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a);
        }
        a = (a * a);
        b = b >> 1; 
    }
    return (ans );
}

void solve() {
    int n;
    cin >> n;
    if(n & 1){
    	int val = n / 2;
    	if(val % 10 != 9){
    		cout << val << " " << val + 1 << "\n";
    	}
    	else{
    		int v = n;
    		int count = 0;
    		while(v % 10 == 9){
    			count++;
    			v /= 10;
    		}
    		int a = 0;
    		int b = 0;
    		if(v & 1){
    			a += (v / 2);
    			b += (v / 2 + 1);
    		}
    		else{
    			a = v / 2;
    			b = v / 2;
    		}
    		for(int i = 0; i < count; i++){
    			if(i & 1){
    				b = b * 10 + 5;
    				a = a * 10 + 4;
    			}
    			else{
    				b = b * 10 + 4;
    				a = a * 10 + 5;
    			}
    		}
    		cout << a << " " << b << "\n";
    	}
    }
    else{
    	cout << n / 2 << " " << n / 2 << "\n";
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