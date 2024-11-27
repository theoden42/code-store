
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
    int n, x;
    cin >> n >> x;
    vector<int> ele(n, 0);
    int odd = 0;
    int even = 0;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	if(ele[i] % 2 == 0){
    		even++;
    	}
    	else{
    		odd++;
    	}
    }
    for(int i = 1; i <= odd && i <= x; i += 2){
    	if(x - i <= even){
    		cout << "YES" << "\n";
    		return;
    	}
    }	
    cout << "NO" << "\n";
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