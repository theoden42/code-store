

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

vector<int> countcomp(vector<pair<int,int>>& vp, int n){
	vector<vector<int>> adj(n + 1);
	for(auto& [a, b] : vp){
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> comp;
	vector<int> vis(n + 1);
	int count = 0;
	function<void(int)> dfs = [&](int src){
		vis[src] = 1;
		count += 1;
		for(auto x: adj[src]) if(!vis[x]){
			dfs(x);
		}
	};

	for(int i = 1; i <= n; i++) if(!vis[i]){ 
		count = 0;
		dfs(i);
		comp.push_back(count);
	}
	return comp;
}

int getmin(vector<int>& vals){
	int n = vals.size();
	int sum = accumulate(all(vals), 0ll);
	vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= sum; j++){
			dp[i][j] |= dp[i - 1][j];
			if(j + vals[i - 1] <= sum && dp[i - 1][j])
				dp[i][j + vals[i - 1]] |= 1;
		}
	}
	int mn = 1e18;
	for(int i = 1; i < sum; i++){
		if(dp[n][i]){
			int a = i;
			int b = sum - i;
			int val = a * a + b * b;
			mn = min(mn, val);
		}
	}

	return mn;
}

void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<pair<int,int>> vp(m);
    for(int i = 0; i < m; i++){
    	cin >> vp[i].first >> vp[i].second;
    }
    vector<int> init = countcomp(vp, n);
    int sz = init.size();

    int mx = 1e18;

    if(sz != 1){
    	mx = min(mx, getmin(init));
    }

    for(int i = 0; i < m; i++){
    	vector<pair<int,int>> temp;
    	for(int j = 0; j < m; j++) if(j != i) { 
    		temp.push_back(vp[j]);
    	}
    	vector<int> comp = countcomp(temp, n);

    	if(comp.size() == sz)
    		continue;

    	mx = min(mx, getmin(comp));
    }
    if(mx == 1e18){
    	cout << "-1\n";
    	return;
    }
    mx += (sz - 1) * c;
    cout << mx << "\n";
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