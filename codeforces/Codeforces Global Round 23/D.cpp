

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

map<pair<int,int>, int> mp;

int dfs(int source, int parent, int k, vector<vector<int>>& adj, vector<int>& score){

	if(mp.find({source, k}) != mp.end())return mp[{source, k}];

	int child = source == 1 ? adj[source].size(): adj[source].size() - 1;

	int sum = k * score[source];

	if(child == 0)return mp[{source, k}] =  sum;

	int mxpt = (k + child - 1) / child;
	int mnpt = k / child;



	vector<int> diff;

	for(auto& x: adj[source]){
		if(parent == x)continue;

		int val = dfs(x, source, mxpt, adj, score);
		int val2 = dfs(x, source, mnpt, adj, score);
		int val3 = val - val2;

		diff.push_back(val3);
		sum += val;
	}

	// debug(mxcount, mncount);

	sort(all(diff));

	for(int i = 0; i < child - k % child; i++){
		sum -= diff[i];
	}

	// debug(source, sum, k);

	return mp[{source, k}] = sum;

}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for(int i = 2; i <= n; i++){
    	int p;
    	cin >> p;
    	adj[p].push_back(i);
    	adj[i].push_back(p);
    }
    vector<int> scores(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> scores[i];
    }

    mp.clear();

    int ans = dfs(1, -1, k, adj, scores);
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