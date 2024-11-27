
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
   int x1, y1, x2, y2, x3, y3;
   cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
   debug(x1, x2, x3, y1, y2, y3);

   if(x1 == x2 || x2 == x3 || x3 == x1){
   		if(y1 == y2 || y2 == y3 || y3 == y1){
   			cout << "NO\n";
   			return;
   		}
   }
   cout << "Yes\n";
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