

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
	vector<int> ca(n), cb(n);
	for(int i = 0; i < n; i++){
		cin >> ca[i];
	}
	for(int i = 0; i < n; i++){
		cin >> cb[i];
	}
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n; i++){
		int u = ca[i];
		int v = cb[i];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> counts;
	vector<int> vis(n + 1);

	function<void(int, int&)> dfs = 
	[&](int source, int& temp){

		vis[source] = 1;
		temp++;	
		for(auto x: adj[source]){
			if(vis[x])continue;
			dfs(x, temp);
		}

	};

	for(int i = 1; i <= n; i++){
		int temp = 0;
		if(!vis[i]){
			dfs(i, temp);	
			counts.push_back(temp);
		}
	}	

	// debug(counts);

	vector<int> countodd, counteven;
	for(auto c: counts){
		if(c & 1){
			countodd.push_back(c);
		}
		else{
			counteven.push_back(c);
		}
	}


	sort(countodd.rbegin(), countodd.rend());
	sort(all(counteven));

	int low = 1;
	int high = n;

	int ans = 0;

	for(auto c: counteven){
		vector<int> valstemp;
		int count1 = 0, count2 = 0;
		for(int i = 1; i <= c / 2; i++){
			count1 += low;
			valstemp.push_back(low++);
		}
		for(int i = 1; i <= c / 2; i++){
			count2 += high;
			valstemp.push_back(high--);
		}
		ans += 2 * (count2 - count1);
	}


	for(auto c: countodd){
		vector<int> valstemp;
		int count1 = 0, count2 = 0;
		for(int i = 1; i <= c / 2; i++){
			if(i != (c + 1) / 2)
				count1 += low;

			valstemp.push_back(low++);
		}

		\

		for(int i = 1; i <= c / 2; i++){
			count2 += high;
			valstemp.push_back(high--);
		}

		ans += 2 * (count2 - count1);

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