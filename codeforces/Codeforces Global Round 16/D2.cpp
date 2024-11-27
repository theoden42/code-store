

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


bool cmp(pair<int,int> a, pair<int,int> b) { 
	if(a.first < b.first)
		return true;
	else if(a.first > b.first)
		return false;
	else 
		return a.second > b.second;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n * m);
	for(int i = 0; i < n * m; i++){
		cin >> a[i];
	}

	map<int, multiset<pair<int,int>> > mp;
	vector<int> temp = a;
	sort(all(temp));
	int row = 0;
	int col = 0;
	for(int i = 0; i < n * m; i++){
		int count = 0; 
		int j = i;
		while(j < n * m && temp[j] == temp[i]) {
			count += 1;
			j += 1;
		}
		for(int k = 1; k <= count; k++) {
			mp[temp[i]].insert({row, -col});
			col += 1;
			if(col == m){
				col = 0;
				row += 1;
			}
		}
		i = j - 1;
	}

	vector<vector<int>> grid(n, vector<int>(m, 0));
	int ans = 0;
	for(int i = 0; i < n * m; i++){
		auto it = *mp[a[i]].begin();
		mp[a[i]].erase(mp[a[i]].begin());
		int row = it.first;
		int col = -it.second;
		for(int j = 0; j < col; j++){
			if(grid[row][j])
				ans += 1;
		}
		grid[row][col] = 1;
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
