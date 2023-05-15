
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

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n, 0);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	mp[ele[i]] = i + 1;
    }

    int mx = -1;
    for(int i = 1; i <= 1000; i++){
    	for(int j = 1; j <= 1000; j++){
    		if(mp.find(i) != mp.end() && mp.find(j) != mp.end()){
    			if(gcd(i, j) == 1){
    				mx = max(mx, mp[i] + mp[j]);
    			}
    		}
    	}
    }
    cout << mx << "\n";
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