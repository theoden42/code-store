
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
    int m;
    int s;
    cin >> m >> s;
    vector<int> b(m);
    for(int i = 0; i < m; i++){
    	cin >> b[i];
    }
    ll sum = 0;
    sum = accumulate(all(b), sum);
    debug(sum);
    ll finalsum = sum + s;
    finalsum = 1 + 8 * finalsum;
    double val = (-1 + sqrt(finalsum)) / 2;

    debug(val);
    if(val != (int)val){
    	cout << "NO\n";
    }
    else{
    	int v = (int)val;
		vector<int> ele(v + 1);
		for(int i = 0; i < m; i++){

			if(b[i] < 1 || b[i] > v || ele[b[i]] == 1){
				cout << "NO\n";
				return;
			}
			ele[b[i]] = 1;
		}
		cout << "YES\n";
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