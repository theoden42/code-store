
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
    vector<int> b(n + 1, 0);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }
    ll sum = 0;	
    sum = accumulate(all(a), sum);


    int mx = 0;
    int ind = -1;
    for(int i = 0; i < n; i++){
    	sum += b[i];
    }

    ll m = sum;
    for(int i = 0; i < n; i++){
    	ll mx = sum - b[i];
    	m = min(m, mx);

    }
    cout << m << "\n";

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