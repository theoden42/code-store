
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
    cin >> n;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<int> prefix(n, 0);
    prefix[0] = 1;
    for(int i = 1; i < n; i++){
    	if(ele[i] >= ele[i - 1]){
    		prefix[i] = prefix[i - 1] + 1;
    	}
    	else{
    		prefix[i] = 1;
    	}
    }
    int m = 0;
    for(auto& x : prefix){
    	m = max(m, x);
    }
    cout << m << "\n";
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