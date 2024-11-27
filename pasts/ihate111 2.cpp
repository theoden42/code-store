
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
    int x;
    cin >> x;

    if(x < 11){
    	cout << "NO" << "\n";
    	return;
    }
    if(x % 11 == 0 || x % 111 == 0){
        cout << "YES" << "\n";
    }
    else{
        int i = 0;
        while(i * 111 <= x){
            // cout << x - i * 111 << "\n";
            if((x - i * 111) % 11 == 0){
                cout << "YES" << "\n";
                return;
            }
            i++;
        }
        cout << "NO" << "\n";
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