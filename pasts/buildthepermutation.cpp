
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
    int n, a, b;
    cin >> n >> a >> b;
    if(a + b > n - 2){
    	cout << "-1\n";
    	return;
    }
    if(b < a){
    	debug(b, a);

    	if(a - b + 1 > (n - 2 * b - 1 )/ 4){
    		cout << "-1\n";
    		return;
    	}
    	for(int i = 1; i <= b; i++){
    		cout << n - i - 1 << " " << i << " ";
    	}
    	int count = n - b - 1;
    	for(int j = 1; j <= a - b + 1; j++){
    		cout << count - 1 << " " << count << " " << count - 2 << " ";
    		count -= 3;
    	}
    	if(count - 3 >= 1){
    		cout << count - 3 << " ";
    	}

    	for(int i = b + 1; i <= count - 4; i++){
    		cout << i << " ";
    	}
    	cout << "\n";
    }
    else{

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