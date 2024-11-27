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

#define int long long

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int len = s.size();
	vector<int> down(len + 1, 0), right(len + 1, 0);
	int cd = 0, cr = 0;

	for(int i = 1; i <= len; i++){
		down[i] = down[i - 1];
		right[i] = right[i - 1];
		if(s[i - 1] == 'D'){
			down[i]++;
			cd++;
		}
		else{
			right[i]++;
			cr++;
		}
	}

	if(cd == 0 || cr == 0){
		cout << n << '\n';
		return;
	}

	int ans = 0;
	int row = 0;
	int col = 0;

	for(int i = 1; i <= n; i++){
		auto it = lower_bound(all(down), i) - down.begin();
		int mx = (right[it] == 0) ? 1 :  1 + (n - cr - 1) + right[it];
		int mnd = (i == 1) ? 0 : max(1ll, i - (n - cd));

		it = lower_bound(all(down), mnd) - down.begin();
		int mn = 1 + right[it];

		int num = mx - mn + 1;
		ans += num;
	}

	int row = cd + 1;
	auto it = lower_bound(all(down), row - 1) - down.begin();
	int col = right[it] + 1;

	ans += 1ll * (n - row + 1) * (n - col + 1);
	cout << ans << "\n";
	
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