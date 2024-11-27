
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
    int q;
    cin >> q;
    string s;
    cin >> s;

    int f0 = -1, l0 = -1, f1 = -1, l1 = -1;

    for(int i = 0; i < n; i++){
    	if(s[i] == '1'){
    		if(f1 == -1){
    			f1 = i;
    		}
    		l1 = i;
    	}
    	else{
    		if(f0 == -1){
    			f0 = i;
    		}
    		l0 = i;
    	}
    }

    for(int i = 0; i < q; i++){
    	int l, r;
    	cin >> l >> r;
    	l--;
    	r--;
    	if(s[l] == '1'){
    		if(f1 < l){
    			cout << "Yes\n";
    			continue;
    		}
    	}
    	else{
    		if(f0 < l){
    			cout << "Yes\n";
    			continue;
    		}
    	}
    	if(s[r] == '1'){
    		if(l1 > r){
    			cout << "Yes\n";
    			continue;
    		}
    	}
    	else{
    		if(l0 > r){
    			cout << "Yes\n";
    			continue;
    		}
    	}

    	cout << "No\n";
    	
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