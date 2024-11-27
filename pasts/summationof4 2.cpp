
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

bool isprime(int n){
	if(n == 1)return false;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

void solve() {
    int n;
    while(cin >> n){
    	if(n > 7){
    		if(n & 1){
    			cout << "2 3 ";
    			n -= 5;
    			for(int j = n - 1; j >= n / 2; j--){
    				if(isprime(j) && isprime(n - j)){
    					cout << j << " " << n - j << "\n";
    					break;
    				}
    			}		
    		} else{
    			cout << "2 2 ";
    			n -= 4;
    			for(int j = n - 1; j >= n / 2; j--){
    				if(isprime(j) && isprime(n - j)){
    					cout << j << " " << n - j << "\n";
    					break;
    				}
    			}

    		}
    	}
    	else{
    		cout << "Impossible.\n";
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