

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
	int n, m;
	cin >> n >> m;

	vector<string> s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}

	auto adj = [&](int r, int c){
		if(r > 0 && s[r - 1][c] == '#')
			return true;
		if(r < n - 1 && s[r + 1][c] == '#')
			return true;
		if(c > 0 && s[r][c - 1] == '#')
			return true;
		if(c < m - 1 && s[r][c + 1] == '#')
			return true;

		return false;
	};

	vector<vector<int>> vis(n, vector<int>(m, 0));

	auto check = [&](int r, int c){
		return (r >= 0 && r < n && c >= 0 && c < m && s[r][c] != '#');
	};

	int mx = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) if(s[i][j] != '#' && !vis[i][j]){

			map<pair<int,int>, int> mp;
			int count = 0;
			queue<pair<int,int>> q;
			q.push({i, j});
			count = 1;
			vis[i][j] = 1;
			mp[{i, j}] = 1;

			while(!q.empty()){
				auto [r, c] = q.front();
				q.pop();

				if(adj(r, c))
					continue;

				if(check(r - 1, c) && mp.find({r - 1, c}) == mp.end()){
					vis[r - 1][c] = 1;
					count += 1;
					q.push({r - 1, c});
					mp[{r - 1, c}] = 1;
				} 

				if(check(r + 1, c) && mp.find({r + 1, c}) == mp.end()){
					vis[r + 1][c] = 1;
					count += 1;
					q.push({r + 1, c});
					mp[{r + 1, c}] = 1;
				}

				if(check(r, c - 1) && mp.find({r, c - 1}) == mp.end()){
					vis[r][c - 1] = 1;
					count += 1;
					q.push({r, c - 1});
					mp[{r, c - 1}] = 1;
				}

				if(check(r, c + 1) && mp.find({r, c + 1}) == mp.end()){
					vis[r][c + 1] = 1;
					count += 1;
					q.push({r, c + 1});
					mp[{r, c + 1}] = 1;
				}
			}
			mx = max(mx, count);
		}
	}

	cout << mx << "\n";
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