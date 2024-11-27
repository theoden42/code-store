

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
	vector<vector<int>> g(7, vector<int>(7));
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			char c;
			cin >> c;
			g[i][j] = (c == 'B');
		}
	}

	auto check = [&](int odd){
		for(int i = 1; i < 6; i++){
			for(int j = 1; j < 6; j++){
				if(g[i][j] && (i + j) % 2 == odd){
					if(g[i][j] == 1 && g[i - 1][j - 1] == 1 && g[i + 1][j - 1] == 1 && g[i + 1][j + 1] == 1 && g[i - 1][j + 1] == 1){
						return 0;
					}
				}
			}
		}

		return 1;
	};

	function<int(int,int,vector<pair<int,int>>&,int)> dfs
	= [&](int ind, int flip, vector<pair<int,int>>& vp, int odd){
		if(flip == 0 || ind == vp.size()){
			return check(odd);
		}
		int ok = 0;
		g[vp[ind].first][vp[ind].second] ^= 1;
		ok |= dfs(ind + 1, flip - 1, vp, odd);
		g[vp[ind].first][vp[ind].second] ^= 1;
		ok |= dfs(ind + 1, flip, vp, odd);

		return ok;
	};

	int ans = 0;
	vector<pair<int,int>> odd, even;
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			if((i + j) & 1){
				odd.push_back({i, j});
			} else {
				even.push_back({i, j});
			}
		}
	}

	for(int i = 0; i <= 4; i++){
		if(dfs(0, i, odd, 1)){
			ans += i;
			break;
		}
	}

	for(int j = 0; j <= 4; j++){
		if(dfs(0, j, even, 0)){
			ans += j;
			break;
		}
	}

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