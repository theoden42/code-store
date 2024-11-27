
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
    if(n == 1){
    	cout << "FastestFinger" << "\n";
    	return;
    }
    if(n == 2 || n % 2 == 1){
    	cout << "Ashishgup" << "\n";
    }
    else{
    	int count = 0;
    	while(n % 2 == 0){
    		n /= 2;
    		count++;
    	}
    	if(n == 1){
    		cout << "FastestFinger" << "\n";
    		return;
    	}
    	if(count == 1){
    		int c = 0;
    		for(int i = 3; i * i <= n; i++){
    			if(n % i == 0){
    				while(n % i == 0){
    					c += 1;
    					n /= i;
    				}
    			}
    		}
    		if(n != 1){
    			c++;
    		}

    		if(c > 1){
    			cout << "Ashishgup" << "\n";
    		}
    		else{
    			cout << "FastestFinger" << "\n";
    		}

    	}
    	else{
    		cout << "Ashishgup" << "\n";
    	}
    }

   	// at any point i get an odd number, i would win onspot
    // i will not subtract by 1 if its even numbert
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