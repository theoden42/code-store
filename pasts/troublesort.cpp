
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
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    vector<int> b(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }
    int flag1 = 0;
    int flag0 = 0;
    for(int i = 0; i < n; i++){
    	if(b[i] == 0){
    		flag0 = 1;
    	}
    	else{
    		flag1 = 1;
    	}
    }
    if(flag1 && flag0){
    	cout << "YES" << "\n";
    }
    else{
    	int fl = 1;
    	for(int i = 1; i < n; i++){
    		if(a[i] < a[i - 1]){
    			fl = 0;
    			break;
    		}
    	}
    	if(fl){
    		cout << "YES" << "\n";
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