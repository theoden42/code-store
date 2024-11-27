

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


void dfs(int source, vector<int>& vis, vector<pair<int,int>>& cord, int d){
	vis[source] = 1;
	int x = cord[source].first;
	int y = cord[source].second;

	for(int i = 0; i < cord.size(); i++){
		int distance = (cord[i].first - x) * (cord[i].first - x) + (cord[i].second - y) * (cord[i].second - y);
		if(distance <= d * d && !vis[i]){
			dfs(i, vis, cord, d);
		}
	}
}

void solve() {
	int n, d;
	cin >> n >> d;
	vector<pair<int,int>> cord(n);
	for(int i = 0; i < n; i++){
		cin >> cord[i].first >> cord[i].second;
	}

	vector<int> vis(n);

	dfs(0, vis, cord, d);

	for(int i = 0; i < n; i++){
		if(vis[i]){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}