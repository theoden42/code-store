
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
    int n, d, k;
    cin >> n >> d >> k;

    if(k == 1){
    	cout << 0 << "\n";
    	return;
    }

    if(d == 1){
    	cout << k - 1 << "\n";
    	return;
    }

    if(n <= d){
    	cout << k - 1 << "\n";
    	return;
    }


    int val = (n - 1) / d + 1;
    int val2 = (n - 1) % d + 1;

    int val3 = (n - 1) / d;

    debug(val, val2, val3, k);

    if(k <= val * val2){
    	int x = k / val;
    	int y = k % val;

    	cout << y * d + x << "\n";
    	return;
    }



    int x = val2 + k / (val3);
    int y = k % val3;

    cout << y * d + x << "\n";



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