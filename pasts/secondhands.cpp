
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
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    if(n > 2 * k){
    	cout << "NO" << "\n";
    	return;
    }
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	mp[ele[i]]++;
    }
    for(auto& x: mp){
    	// cout << x.first << " " << x.second << "\n";
    	if(x.second >= 3){
    		cout << "NO" << "\n";
    		return;
    	}
    }
    cout << "YES" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}