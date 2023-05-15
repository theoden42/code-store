
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
    if(n % 2 == 1){
    	cout << (n - 1) / 2 << " " << (n - 1) / 2 << " " << 1 << "\n";
    }
    else{
    	int x = n / 2;
    	if(x % 2 == 0){
    		cout << (x / 2) << " " << x << " " << (x / 2) << "\n";
    	}
    	else{
    		cout << x - 1 << " " << x - 1 << " " << 2 << "\n";
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