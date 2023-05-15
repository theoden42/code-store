
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
    string s;
    cin >> s;
    ll sum = 0;
    ll paranoid = 0;
    ll count = 1;
    for(int i = 1; i < n; i++){
    	if(s[i] != s[i - 1]){
    		sum += (paranoid + count);
    		paranoid += count;
    		count = 1;
    	}
    	else{
    		count++;
    	}
    }
    cout << (sum + n) << "\n";
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