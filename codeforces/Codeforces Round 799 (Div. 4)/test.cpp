

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
	vector<int> p(n + 1);
	for(int i = 1; i <= n; i++){
		int x;
		p[x] = i;
	}

	vector<int> vis(n + 1);
	int ans = 1;

	function<int(vector<int>&, int)> repeat = 
	[&](vector<int>& components, int period){
		int sz = components.size();
		for(int i = 0; i < sz; i++){
			if(s[i] != s[(i + period) % sz])return false;
		}
		return true;
	};


	function<int(vector<int>&)> check =
	[&](vector<int>& components){
		int sz = components.size();
		int mn = sz;

		for(int i = 1; i * i <= sz; i++){
			if(sz % i == 0){
				int f1 = i;
				int f2 = sz / i;
				if(repeat(components, f1)){
					mn = min(mn, f1);
				}
				if(repeat(components, f2)){
					mn = min(mn, f2);
				}
			}
		}
		return mn;
	};

	for(int i = 1; i <= n; i++){
		if(vis[i])continue;

		vector<int> components;
		components.push_back(i);
		vis[i] = 1;
		int nw = p[i];
		while(nw != i){
			components.push_back(nw);
			vis[nw] = 1;
			nw = p[nw];
		}

		int val = check(components);
		ans = lcm(ans, val);
	}

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