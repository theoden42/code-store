
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
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count0 = 0;
    int count1 = 0;
    for(int i = 0; i < s.size(); i++){
    	if(s[i] == '1')count1++;
    	else count0++;
    }


    int val1 = (1 << count1);
    int val2 = (1 << n) - (1 << count0) + 1;
    debug(val1, val2);
    for(int i = val1; i <= val2; i++){
    	cout << i << " ";
    }

    cout << "\n";


}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}