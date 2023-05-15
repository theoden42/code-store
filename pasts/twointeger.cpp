
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



ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

ll gcd(int a, int b){
	return b ? gcd(b, a % b) : (ll)a;
}

ll lcm(int a, int b){
	return ((1ll * a * b) / gcd(a, b));
}

ll lcm(ll a, ll b){
	return ((a * b) / gcd(a, b));
}


void solve() {
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    int c = max(b, a);

    if(g == 1){
    	cout << c + 1 << " " << c + 2 << "\n";
    	return;
    }
    else{
    	cout << c * g << " " << (c + 1) * g << "\n";
    }

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