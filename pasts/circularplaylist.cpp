
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
	ll n, t;
	cin >> n >> t;
	vector<int> ele(n);
	for(int i = 0; i < n; i++){
		cin >> ele[i];
	}

	vector<int> prefix(n, 0);
	prefix[0] = ele[0];
	for(int i = 1; i < n; i++){
		prefix[i] = prefix[i - 1] + ele[i];
	}

	int val = t % prefix[n - 1];
	int ans = 0;

	debug(val, prefix);



	for(int i = 0; i < n; i++){
		if(prefix[i] > val){
			ans = i;
			break;
		}
	}

	
	int time = (ans == 0)? val : val - prefix[ans - 1];
	cout << ans + 1 << " " << time << "\n";

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