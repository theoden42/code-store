
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
    if(m < n - 1 || m > 2 * (n + 1)){
    	cout << -1 << "\n";
    	return;
    }

    if(m == n - 1){
    	for(int i = 0; i < n - 1; i++){
    		cout << "01";
    	}
    	cout << "0";
    	cout << "\n";
    	return;
    }

    int count = m - n - 1;
    for(int i = 0; i < n; i++){
    	if(count > 0){
    		cout << "11";
    		m -= 2;
			count--;
    	}
    	else{
    		if(m > 0){
    			cout << "1";
    			m -= 1;
    		}
    	}
    	cout << "0";
    }
    for(int i = 1; i <= m; i++){
    	cout << 1;
    }

    cout << "\n";
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