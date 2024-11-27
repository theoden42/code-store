

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<int>> 
	podd(n + 1, vector<int>(26, 0)), 
	peven(n + 1, vector<int>(26, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			podd[i + 1] = podd[i];
			peven[i + 1] = peven[i];
		}
		if(i & 1){
			podd[i + 1][s[i] - 'a'] += 1;
		} else {
			peven[i + 1][s[i] - 'a'] += 1;
		}
	}

	if(n % 2 == 0){
		int mx1 = 0, mx2 = 0;
		for(int j = 0; j < 26; j++){
			mx1 = max(mx1, peven[n][j]);
			mx2 = max(mx2, podd[n][j]);
		}
		int ans = n - mx1 - mx2;
		cout << ans << "\n";
		return;
	}

	int ans = 1e9;
	vector<int> curreven(26, 0), currodd(26, 0);
	for(int i = 0; i < n; i++){
		// we remove the ith character
		int mxodd = 0, mxeven = 0;
		for(int j = 0; j < 26; j++){
			int curr1 = currodd[j] + (peven[n][j] - peven[i + 1][j]);
			int curr2 = curreven[j] + (podd[n][j] - podd[i + 1][j]);
			mxodd = max(mxodd, curr1);
			mxeven = max(mxeven, curr2);
		}
		int temp_ans = n - mxodd - mxeven;
		ans = min(ans, temp_ans);
		if(i & 1){
			currodd[s[i] - 'a'] += 1;
		} else {
			curreven[s[i] - 'a'] += 1;
		}
	}

	cout << max(1, ans) << "\n";

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