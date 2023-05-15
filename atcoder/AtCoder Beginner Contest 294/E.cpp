
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
	int l, n1, n2;
	cin >> l >> n1 >> n2;

	vector<pair<int,int>> a(n1), b(n2);


	for(int i = 0; i < n1; i++){
		int v, x;
		cin >> v >> x;
		a[i] = {v, x};
	}	

	for(int i = 0; i < n2; i++){
		int v,x;
		cin >> v >> x;
		b[i] = {v, x};
	}

	int i = 0;
	int j = 0;

	int ans = 0;


	while(i < n1 && j < n2){
		int x = a[i].first;
		int y = b[j].first;
		int oc1 = a[i].second;
		int oc2 = b[j].second;


		if(x == y){
			ans += min(oc1, oc2);
		}

		if(oc1 < oc2){
			i++;
			b[j].second -= oc1;
		}
		else if(oc1 == oc2){
			i++;
			j++;
		}
		else{
			a[i].second -= oc2;
			j++;
		}
	}

	cout << ans << "\n";

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