
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
    ll m, n;
    cin >> m >> n;
    vector<ll> t(n, 0);
    vector<ll> y(n, 0);
    vector<ll> z(n, 0);
    vector<ll> ans(n, 0);
    for(int i = 0; i < n; i++){
        cin >> t[i] >> z[i] >> y[i];
    }
    ll l = 0;
    ll u = 1e9;
    ll time = 1e8;
    while(l <= u){
        ll mid = l + (u - l)/2;
        ll count = 0;   
        vector<ll> temp(n, 0);
        for(int i = 0; i < n; i++){
            ll lower = 0;
            ll upper = mid / t[i];
            ll tempans = 0;
            while(lower <= upper){
                ll xtemp = lower + (upper - lower) / 2;
                ll val = xtemp * t[i] + (xtemp / z[i]) * y[i];
                if(xtemp % z[i] == 0 && xtemp != 0){
                    val -= y[i];
                }
                if(val <= mid){
                    tempans = xtemp;
                    lower = xtemp + 1;
                }
                else{
                    upper = xtemp - 1;
                }
            }
            temp[i] = tempans;
            count += tempans;
        }
        // cout << u  << " "<<  mid << " " << count << "\n";
        if(count >= m){
            ans = temp;
            time = mid;
            u = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << time << "\n";
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += (ans[i]);
        if(sum > m){
            ans[i] = max(0ll , m - sum + ans[i]);
            cout << ans[i] << " ";
            continue;
        }
        cout << ans[i] << " ";
    }
    cout << endl;
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