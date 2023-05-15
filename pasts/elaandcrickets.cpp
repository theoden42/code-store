
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
    int r1, c1, r2, c2, r3, c3;
    cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
    int x, y;
    cin >> x >> y;

    int midx = 0;
    int midy = 0;
    if((r1 == r2 && c1 == c3) || (r1 == r3 && c1 == c2)){
        midx = r1;
        midy = c1;
    }
    else if((r2 == r1 && c2 == c3) || (r2 == r3 && c2 == c1)){
        midx = r2;
        midy = c2;
    }
    else{
        midx = r3;
        midy = c3;
    }
    debug(r1, c1, r2, c2, r3, c3, x, y);

    if(midx == 1 && midy == 1){
        if(x == 1 || y == 1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }
    if(midx == 1 && midy == n){
        if(x == 1 || y == n){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }
    if(midx == n && midy == 1){
        if(x == n || y == 1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }
    if(midx == n && midy == n){
        if(x == n || y == n){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }

    int d1 = abs(x - midx);
    int d2 = abs(y - midy);

    debug(d1, d2, midx, midy);

    if((d1 & 1) && (d2 & 1)){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";    
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