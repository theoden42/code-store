
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define int long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}

	int q;
	cin >> q;
	vector<int> prefix(n, v[0]);
	for(int i = 1; i < n; i++){
		prefix[i] = v[i] + prefix[i - 1];
	}



	// vector<int> suffix(n, 0);
	// suffix[n - 1] = v[n - 1];
	// for(int i = n - 2; i >= 0; i--){
	// 	suffix[i] = suffix[i - 1] + v[i];
	// }

	vector<int> max_prefix(n, 0);
	max_prefix[0] = v[0];

	for(int i = 1; i < n; i++){
		int water = (i + 1) *  max_prefix[i - 1];
		int it = upper_bound(all(prefix), water) - prefix.begin();

		if(it == i){
			max_prefix[i] = 
		}

	}



	for(int i = 1; i <= q; i++){
		int t;
		cin >> t;	

	}
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
  //  cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}