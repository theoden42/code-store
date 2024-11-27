
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
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    a = a / g;
    b = b / g;
   	int count = 0;

   	debug(a, b);
   	while(a % 2 == 0){
   		count++; 
   		a /= 2;
   	}
   	while(b % 2 == 0){
   		count++;
   		b /= 2;
   	}
   	while(a % 3 == 0){
   		count++;
   		a /= 3;
   	}
   	while(b % 3 == 0){
   		count++;
   		b /= 3;
   	}
   	while(a % 5 == 0){
   		a /= 5;
   		count++;
   	}
   	while(b % 5 == 0){
   		b /= 5;
   		count++;
   	}
   	if(a != 1 || b != 1){
   		cout << "-1\n";
   		return;
   	}
   	else{
   		cout << count << "\n";
   	}
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