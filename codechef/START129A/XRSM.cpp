

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
	int n, s;
	cin >> n >> s;
	if(n == 1 && s != 0){
		cout << "-1\n";
		return;
	}

	if(s & 1 || s < n){
		cout << "-1\n";
		return;
	}

	vector<int> ans(n);
	queue<int> q;

	for(int i = 0; i < n; i++){
		q.push(i);
	}
	
	for(int i = 31; i >= 1; i--){
		if(s >> i & 1){
			int a = q.front();
			q.pop();
			int b = q.front();
			q.pop();
			ans[a] |= (1 << (i - 1));
			ans[b] |= (1 << (i - 1));
			q.push(a);
			q.push(b);
		}
	}
	sort(all(ans));
	int sum = 0;
	int xr = 0;
	int mn = 1e9 + 5;
	for(int i = 0; i < n; i++){
		mn = min(mn, ans[i]);
		xr ^= ans[i];
		sum += ans[i];
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