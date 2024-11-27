
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
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;


    int alice = a1;
    int bob = a1;
    int count = a1;


    if(alice == 0 && bob == 0){
    	cout << count + 1 << "\n";
    	return;
    }


    count += 2 * min(a3, a2);

    if(a3 > a2){
    	int temp = min(alice + 1, a3 - a2);
    	count += temp;
    	alice -= temp;
    	bob += temp;
    }else{
    	int temp = min(bob + 1, a2 - a3);
    	count += temp;
    	bob -= temp;
    	alice += temp;
    }

    count += min({alice + 1, bob + 1, a4});
    cout << count << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}