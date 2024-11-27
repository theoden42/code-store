
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
    string a, b;
    cin >> a >> b;
    int x, y, z, w;
    x = y = z = w = 0;

    for(int i = 0; i < n; i++){
        if(a[i] == '1' && b[i] == '1')x++;
        if(a[i] == '1' && b[i] == '0')y++;
        if(a[i] == '0' && b[i] == '1')z++;
        if(a[i] == '0' && b[i] == '0')w++;
    }

    debug(x, y, z, w);

    if(((y != z) && (x != w + 1))){
        cout << "-1\n";
        return;
    }
    else{
        int mn = INF;
        
        if(y == z)
            mn = min(mn, 2 * y);

        if(x == w + 1)
            mn = min(mn, (2 * (x - 1) + 1));
        
        cout << mn << "\n";
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