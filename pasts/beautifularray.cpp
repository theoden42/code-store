
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
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


void solve() {
    int n, k, b, s;
    cin >> n >> k >> b >> s;
    vector<int> ans(n);
    int val = b / n;
    for(int i = 0; i < n; i++){
    	ans[i] = k * val;
    }
    for(int i = 0; i < b % n; i++){
    	ans[i] += k;
    }

    ll sum = 0;
    sum = accumulate(all(ans), sum);
    if(sum > s){
    	cout << "-1\n";
    	return;
    }
    s -= sum;
    for(int i = 0; i < n; i++){
    	ans[i] += min(k - 1, s);
    	s -= min(k - 1, s);
    }
    if(s != 0){
    	cout << "-1\n";
    	return;
    }
    for(int i = 0; i < n; i++){
    	cout << ans[i] << " ";
    }
    cout << "\n";


}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}