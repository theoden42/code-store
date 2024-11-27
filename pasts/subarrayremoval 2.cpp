
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
    vector<int> ele(n, 0);
    int one = 0;
    int zero = 0;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	if(ele[i] == 1)one++;
    	else zero++;
    }

    debug(one, zero);

    if(zero > one){
    	cout << one << "\n";
    }
    else{
    	ll sum = 0;
    	sum += zero;
    	one = one - zero;
    	zero = 0;
    	sum += one / 3;
    	cout << sum << "\n";

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