
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
	ll n, k;
	cin >> n >> k;
	vector<ll> ele(n, 0);
	for(int i = 0; i < n; i++){
		cin >> ele[i];
	}
	int j = -1;
	multiset<ll> mst;
	ll count = 0;
	for(int i = 0; i < n; i++){
		while(j < n && (mst.empty() || *(mst.rbegin()) - *mst.begin() <= k)){
			j++;
			mst.insert(ele[j]);
		}
		debug(i, j, mst, *mst.rbegin(), *mst.begin());
		count += j - i;
		mst.erase(mst.find(ele[i]));
	}
	cout << count << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}