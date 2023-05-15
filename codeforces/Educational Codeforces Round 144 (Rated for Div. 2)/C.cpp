
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
const ll MOD = 998244353;
const ll INF = 1e9;

void solve() {
    int l , r;
    cin >> l >> r;
    int n = l;
    int count = 0;

    while(2 * n <= r){
    	n *= 2;
    	count++;
    }

    cout << count + 1 << " ";

    if(count == 0){
    	cout << (r - l + 1) << "\n";
    	return;
    }


    n /= l;
    ll total = 0;
    total = (total + r / n - l + 1) % MOD;




    n /= 2;
    n *= 3;

    // debug(n);

    int temp = (r / n - l + 1) % MOD;

    if(temp > 0){
    	// debug(temp, count, temp * count);
    	total = (total + (temp * (count) % MOD)) % MOD;
    }

    cout << total << "\n";

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