

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

vector<pair<int,int>> dis = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int check(int i, int j, vector<vector<int>>& a){
	int n = a.size();
	int m = a[0].size();
	if(i >= 0 && i < n && j >= 0 && j < m && a[i][j] > 0)return true;
	return false;
}

int dfs(int i, int j, vector<vector<int>>& a, vector<vector<int>>& vis){
	int sum = a[i][j];
	vis[i][j] = 1;
	for(auto d: dis){
		int nx = i + d.first;
		int ny = j + d.second;
		if(check(nx, ny, a) && !vis[nx][ny])
			sum += dfs(nx, ny, a, vis);
	}
	return sum;
}

void solve() {
   int n, m;
   cin >> n >> m;
   vector<vector<int>> a(n, vector<int>(m, 0));
   for(int i = 0; i < n; ++i){
   	for(int j = 0; j < m; j++){
   		cin >> a[i][j];
   	}
   }

   vector<vector<int>> vis(n, vector<int>(m, 0));
   int mx = 0;

   for(int i = 0; i < n; i++){
   	for(int j = 0; j < m; j++){
   		if(a[i][j] > 0 && !vis[i][j]){
   			int ans = dfs(i, j, a, vis);
   			mx = max(mx, ans);
   		}
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