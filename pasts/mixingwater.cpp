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
    ll h, c, t; 
    cin >> h >> c >> t;

    if(h + c >= 2 * t){
        cout << 2 << "\n";
        return;
    }
    
    ll l = 1;
    ll u = 1e9;
    double mn = 1e15;
    ll ans = 0;

    for(int i = 0; i <= 64; i++){
        ll mid = l + (u - l) / 2;
        double avg = (h * mid) + c * (mid - 1);
        avg = avg / (2.0 * mid - 1);
        if(mn > abs(t - avg)){
            mn = abs(t - avg);
            ans = mid;
        }
        if(avg < t){
            u = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    if(ans == 0){
        cout << 2 << "\n";
        return;
    }
    cout << 2 * ans - 1 << "\n";

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