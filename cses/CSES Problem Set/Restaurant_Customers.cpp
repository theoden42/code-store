
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
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    sort(all(a));
    sort(all(b));
    int count = 0;
    int i = 0;
    int j = 0;
    int mx = 0;
    while(i < n && j < n){
        if(a[i] < b[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        mx = max(mx, count);
    }
    while(i < n){
        count++;
        i++;
        mx = max(mx, count);
    }
    while(j < n){
        count--;
        j++;
    }
    cout << mx << "\n";

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