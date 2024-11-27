
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

pair<int,int> check(int x, int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			if(i != x && n / i != x && i != n / i){
				return {i, n / i};
			}
		}
	}
	return {-1, -1};
}

void solve() {
    int n;
    cin >> n;
    for(int i = 2; i * i <= n; i++){
    	if(n % i == 0){
    		int x = i;
    		int y = n / i;
    		auto a1 = check(x, n / i);
    		auto a2 = check(y, i);
    		if(a1.first != -1){
    			cout << "YES" << "\n";
    			cout << i << " " << a1.first << " " << a1.second << "\n";
    			return;
    		}
    		else if(a2.first != -1){
    			cout << "YES" << "\n";
    			cout << i << " " << a2.first << " " << a2.second << "\n";
    			return;
    		}
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