
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
    ll n, h;
    cin >> n >> h;
    vector<ll> pow(n);
    for(int i = 0; i < n; i++){
    	cin >> pow[i];
    }


    sort(all(pow));

    h *= 12;

    debug(h);

    int count = 0;
    int count2 = 0;
    for(int i = 0; i < n; i++){
    	if(pow[i] < h && pow[i] != 1){
    		count++;
    		h += pow[i] / 2;
    	}
    	else if(pow[i] == 1){
    		count2++;
    	}
    }
    if(count2 > 0)cout << count + 1 << "\n";
    else cout << count << "\n";

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