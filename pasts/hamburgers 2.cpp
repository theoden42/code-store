
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
   string s;
   cin >> s;
   int n = s.size();
   ll b = 0, ss = 0, c = 0;

   ll na, nb, nc;
   cin >> na >> nb >> nc;

   ll pa, pb, pc;
   cin >> pa >> pb >> pc;

   ll r;
   cin >> r;

   for(int i = 0; i < n; i++){
   		if(s[i] == 'B'){
   			b++;
   		}
   		else if(s[i] == 'S'){
   			ss++;
   		}
   		else{
   			c++;
   		}
   } 
   ll l = 0;
   ll u = 1e15;	
   ll mx = 0;
   while(l <= u){
   		ll mid = l + (u - l)/2;	
   		ll bread = max(0ll, mid * b - na);
   		ll sausage = max(0ll, mid * ss - nb);
   		ll cheese = max(0ll, mid * c - nc);
   		ll cost = pa * bread + pb * sausage + pc * cheese;
   		if(cost <= r){
   			mx = max(mx, mid);
   			l = mid + 1;
   		}
   		else{
   			u = mid - 1;
   		}
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