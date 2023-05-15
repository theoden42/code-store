
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9; 
const ld EPS = 1e-9;

bool prime[MAX_N];

void SieveOfEratosthenes()
{
	for(int i = 0; i < MAX_N; i++){
		prime[i] = true;
	}
    for (int p = 2; p * p < MAX_N; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i < MAX_N; i += p)
                prime[i] = false;
        }
    }
}
 

void solve() {
	int n;
	cin >> n;	
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		if(x == 1){
			cout << "NO" << "\n";
			continue;
		}
		double y = sqrt(x);
		if(y - (int)y == 0){
			if(prime[(int)y])
				cout << "YES" << "\n";
			else{
				cout << "NO" << "\n";
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
    //cin >> tc;
    SieveOfEratosthenes();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}