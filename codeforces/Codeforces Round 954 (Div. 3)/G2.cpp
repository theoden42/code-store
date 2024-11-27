

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
	vector<int> p(n + 1);
	vector<vector<int>> divisor(n + 1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n && i * j <= n; j++){
			divisor[i * j].push_back(i);
		}
	}
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	vector<int> freq(n + 1);
	vector<vector<int>> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++){
		int g = gcd(i, p[i]);
		int at = p[i] / g;
		int bt = i / g;
		a[at].push_back(bt);
		b[bt].push_back(at);
	}

	int ans = 0;
	for(int bt = 1; bt <= n; bt++){
		vector<int> temp;
		int f = 1;
		for(int j = 1; j <= n && bt * j <= n; j++){
			int val = j * bt;
			for(auto& x: a[val]){
				temp.push_back(x);
				freq[x] += 1;
			}
		}
		for(auto at: b[bt]){
			for(auto div: divisor[at]){
				ans += freq[div];
			}
		}
		for(auto& x: temp){
			freq[x] -= 1;
		}
	}

	for(int i = 1; i <= n; i++){
		int g = gcd(i, p[i]);
		if(i / g == 1){
			ans -= 1;
		}
	} 
	ans /= 2;
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