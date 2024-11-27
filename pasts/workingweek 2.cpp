
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
    int l1 = 1;
    int l2 = -1;
    int l3 = -1;
    if(n % 3 == 0){
    	l2 = 2 * (n / 3) - 3;
    	l3 = n / 3  - 1;
    }
    else if(n % 3 == 1){
    	l2 = 2 * (n / 3) - 2;
    	l3 = n / 3 - 1;
    }
    else{
    	l2 = 2 * (n / 3) - 2;
    	l3 = n / 3;
    }

    cout << min({abs(l2 - l1), abs(l3 - l2), abs(l1 - l3)}) << "\n";
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