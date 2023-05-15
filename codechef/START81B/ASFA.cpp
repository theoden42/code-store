
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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    int c0 = 0, c1 = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] == 1){
    		c1++;
    	} 
    	else{
    		c0++;
    	}
    }

    if(n & 1){
    	cout << -1 << '\n';
    	return;
    }

    if(c0 == c1){
    	cout << 0 << "\n";
    	return;
    }
    else if(c0 > c1){
    	if(c1 == 0){
    		cout << "-1\n";
    		return;
    	}
    	cout << (c0 - c1) / 2 << '\n';
    	return;
    }
    else{
    	int count = 0;
    	while(c1 > c0 && c1 > 1){
    		c1 -= 2;
    		c0 += 2;
    		count++;
    	}
    	if(c1 > 0){
    		cout << count + n / 2 - c1 << "\n";
    	}
    	else{
    		cout << "-1\n";
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