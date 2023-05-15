
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
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
    	cin >> x[i];
    }

    vector<ll> prefix(n + 1, 0);
    for(int i = 1; i <= n; i++){
    	prefix[i] = x[i - 1] + prefix[i - 1];
    }

    for(int i = 1; i <= q; i++){
    	int a, b;
    	cin >> a >> b;
    	cout << prefix[b] - prefix[a - 1] << "\n";
    }
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