

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

int find(vector<vector<int>> val, int k){
	int n = val.size();
	int m = val[0].size();
	vector<vector<int>> cols(m, vector<int>(n + 1)), rows(n, vector<int>(m + 1));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			rows[i][j + 1] = rows[i][j];
			if(val[i][j] == 1){
				rows[i][j + 1] += 1;	
			}
		}
	}
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			cols[j][i + 1] = cols[j][i];
			if(val[i][j] == 1){
				cols[j][i + 1] += 1;
			}
		}
	}
	map<int, int> mp;
	int count = 0;
	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp.find(i - j) == mp.end())
                mp[i - j] = count++;
        }
	}
	vector<ordset<int>> dags(count + 1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(val[i][j] == 1){
				dags[mp[i - j]].insert(i);
			}
		}
	}
	int curr = 0;
	for(int j = 0; j <= k && j < m; j++){
		if(val[0][j] == 1){
			curr += 1;
		}
	}
	int mx = curr;
	vector<vector<int>> vis(n, vector<int>(m));
	function<void(int,int,int)> dfs = [&](int x, int y, int c){
        mx = max(mx, c);
        vis[x][y] = 1;
		if(x + 1 < n && !vis[x + 1][y]){
            int add = rows[x + 1][min(m, y + k + 1)] - rows[x + 1][y];
            int diag = x - y - k;
            int sub = (mp.find(diag) != mp.end()) ? dags[mp[diag]].order_of_key(x + 1) - dags[mp[diag]].order_of_key(x - k) : 0;
            dfs(x + 1, y, c + add - sub);
		}
        if(y + 1 < m && !vis[x][y + 1]){
            int sub = cols[y][x + 1] - cols[y][max(0, x - k)];
            int diag = x - y - k - 1;
            int add = (mp.find(diag) != mp.end()) ? dags[mp[diag]].order_of_key(x + 1) - dags[mp[diag]].order_of_key(x - k) : 0;
            dfs(x, y + 1, c + add - sub);
        }
	}; dfs(0, 0, curr);
    return mx;
}

vector<vector<int>> rotate(vector<vector<int>>& val){
    int n = val.size();
    int m = val[0].size();
    vector<vector<int>> nw(m, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            nw[j][n - 1 - i] = val[i][j];
        }
    }
    return nw;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> temp(n);
    for(int i = 0; i < n; i++){
        cin >> temp[i];
    }
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            v[i][j] = (temp[i][j] == '#');
        }
    }
    int ans = find(v, k);
    v = rotate(v);
    ans = max(ans, find(v, k));
    v = rotate(v);
    ans = max(ans, find(v, k));
    v = rotate(v);
    ans = max(ans, find(v, k));

    cout << ans << "\n";
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