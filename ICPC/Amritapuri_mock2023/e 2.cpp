
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
    vector<int> l(2 * n + 1);
    for(int i = 1; i <= 2 * n; i++){
    	cin >> l[i];
    }

    sort(all(l));

    double x = (l[1] + l[2 * n]) / 2.0;
    for(int i = 2; i <= n; i++){
    	double temp = (l[i] + l[2 * n + 1 - i]) / 2.0;
    	if(temp != x){
    		cout << "IMBALANCED\n";
    		return;
    	}
    }
    cout << "PERFECT\n";
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