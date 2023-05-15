
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
	vector<int> ele(n);

	for(int i = 0; i < n; i++){
		cin >> ele[i];
	}

	int count0 = 0;
	int count1 = 0;
	ll inv = 0;
	for(int i = n - 1; i >= 0; i--){
		if(ele[i] == 1){
			inv = inv + count0;
			count1++;
		}
		else{
			count0++;
		}
	}

	debug(inv);

	ll mx = inv;
	count0 = 0;
	for(int i = n - 1; i >= 0; i--){
		if(ele[i] == 0){
			ll nw = inv - count1 + count0;
			mx = max(mx, nw);
			debug(i, nw);
			count0++;
		}
		else{
			count1--;
			ll nw = inv - count0 + count1;
			mx = max(mx, nw);
			debug(i, nw);
		}
	}
	cout << mx << "\n";
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