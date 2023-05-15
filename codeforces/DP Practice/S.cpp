
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
const ll INF = 1e9 + 5;


int calc(int l, int r, vector<int>& a){

    debug(l, r);

    if(r < l){
        return 0;
    }

    int sz = r - l + 1;
    if(sz == 1)return 1;



    int mn = INF;
    for(int i = l; i <= r; i++){
        mn = min(mn, a[i]);
    }

    for(int i = l; i <= r; i++){
        a[i] -= mn;
    }

    int ans = mn;

    int lb = l;
    for(int i = l; i <= r; i++){
        if(a[i] == 0){
            if(lb <= i - 1){
                ans += calc(lb, i - 1, a);
            }
            lb = i + 1;
        }
    }

    ans += calc(lb, r, a);
    debug(sz, ans);
    return min(sz, ans);

}

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n);
    for(int i = 0; i < n; ++i){
    	cin >> ele[i];
    }

    int ans = calc(0, n - 1, ele);
    cout << ans << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}