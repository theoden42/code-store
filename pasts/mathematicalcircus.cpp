
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n, k;
    cin >> n >> k;
    int v = n % 4;
    if(k % 2 == 1){
    	cout << "YES" << "\n";
    	for(int i = 1; i <= n; i += 2){
    		cout << i << " " << i + 1 << "\n"; 
    	}
    }
    else{
    	if((n % 4 == 0 || n % 4 == 2) && k % 4 == 2){
    		cout << "YES" << "\n";
    		for(int i = 1; i <= n; i++){
    		if(i % 4 == 0){
    			cout << i - 1 << " " << i << "\n";
    		}
    		else{
    			if(i % 4 == 2){
    				cout << i << " " << i - 1 << "\n";
    			}
    			else{
    				continue;
    			}
    		}
    		}
    	}
    	else{
    		cout << "NO" << "\n";
    	}

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