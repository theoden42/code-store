
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
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    int flag = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == '2'){
    		if(flag == 0){
    			a[i] = 1;
    			b[i] = 1;	
    		}
    		else{
    			a[i] = 0;
    			b[i] = 2;
    		}
    	}
    	else if(s[i] == '1'){
    		if(flag == 0){
    			a[i] = 1;
    			b[i] = 0;
    			flag = 1;
    		}
    		else{
    			a[i] = 0;
    			b[i] = 1;
    		}
    	}
    	else{WWW
    		if(flag == 0){
    			a[i] = 0;
    			b[i] = 0;
    		}
    		else{
    			a[i] = 0;
    			b[i] = 0;
    		}
    	}	
    }
    for(auto& x: a){
    	cout << x;
    }
    cout << "\n";
    for(auto& x: b){
    	cout << x;
    }
    cout << '\n';
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