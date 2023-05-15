
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
    vector<ll> pref(n, 0);
    ll m = 0;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	if(i == 0){
    		pref[i] = ele[i];
    	}
    	else{
    		pref[i] = ele[i] + pref[i - 1];
    	}
    }
    for(int i = -1; i < n; i++){
    	ll sum = 0;
    	if(i >= 0){
    		sum += pref[i] - 1ll * (i + 1) * k;
    	}
    	ll pow = 2;
    	for(int j = i + 1; j < min(n, i + 31); j++){
    		sum += (ele[j] >> (j - i));
    	}
    	// cout << sum << "\n";
    	m = max(m, sum);
    }
    if(m < 0){
    	cout << 0 << "\n";
    }
    else{
    	cout << m << "\n";
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