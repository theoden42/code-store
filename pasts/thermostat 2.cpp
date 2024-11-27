
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
        int l, r, x; cin >> l >> r >> x;
        int a, b; cin >> a >> b;
        if(a == b){
            cout << 0 << endl;
        }
        else if(b >= l && b <= r){
            if(abs(a - b) >= x){
                cout << 1 << endl;
            }
            else if(abs(a - l) < x && abs(a - r) < x){
                cout << -1 << endl;
            }
            else if(abs(l - b) >= x && abs(a - l) >= x){
                cout << 2 << endl;
            }
            else if(abs(r - b) >= x && abs(r - a) >= x){
                cout << 2 << endl;
            }
            else if(abs(l - a) >= x && abs(l - r) >= x && abs(r - b) >= x){
                cout << 3 << endl;
            }
            else if(abs(r - a) >= x && abs(l - r) >= x && abs(l - b) >= x){
                cout << 3 << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        else{
            cout << -1 << endl;
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