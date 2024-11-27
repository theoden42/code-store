

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
vector d(61, vector(61, vector(61, vector<int>(61, 1e18))));
vector vis(61, vector(61, vector(61, vector<int>(61, 0))));

void solve() {	
	int n;
	cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}

	vector<pair<int,int>> dis = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
	auto move = [&](int i, int j, int ind){
		int ni = i + dis[ind].first;
		int nj = j + dis[ind].second;
		if(ni >= 0 && ni < n && nj >= 0 && nj < n && s[ni][nj] != '#')
			return make_pair(ni, nj);
		else 
			return make_pair(i, j);
	};

	vector<vector<int>> p;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(s[i][j] == 'P')
				p.push_back({i, j});
		}
	}

	d[p[0][0]][p[0][1]][p[1][0]][p[1][1]] = 0;
	queue<vector<int>> q;
	q.push({p[0][0], p[0][1], p[1][0], p[1][1]});
	vis[p[0][0]][p[0][1]][p[1][0]][p[1][1]] = 1;

	while(!q.empty()){
		auto index = q.front();
		q.pop();
		int i = index[0];
		int j = index[1];
		int k = index[2];
		int l = index[3];

		for(int mv = 0; mv < 4; mv++){
			auto [ni, nj] = move(i, j, mv);	
			auto [nk, nl] = move(k, l, mv);
			if(!vis[ni][nj][nk][nl]){ 
				d[ni][nj][nk][nl] = d[i][j][k][l] + 1;
				vis[ni][nj][nk][nl] = 1;
				q.push({ni, nj, nk, nl});
			}
		} 
	}

	int ans = 1e18;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans = min(ans, d[i][j][i][j]);
		}
	}
	if(ans == 1e18){
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}

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