

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

vector<pair<int,int>> mv = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void solve() {
	int n;
	cin >> n;

	vector<pair<int,int>> points(n);
	map<pair<int,int>, int> mp;

	for(int i = 0; i < n; i++){
		cin >> points[i].first >> points[i].second;
		mp[{points[i].first, points[i].second}] = i;
	}

	vector<pair<int,int>> ans(n, {-1, -1});
	vector<int> vis(n, 0);

	queue<pair<int,int>> q;

	for(int i = 0; i < n; i++){
		for(auto d: mv){
			int nx = points[i].first + d.first;
			int ny = points[i].second + d.second;
			if(mp.find({nx, ny}) == mp.end()){
				q.push(points[i]);
				vis[i] = 1;
				ans[i] = {nx, ny};
				break;
			}
		}
	}

	while(!q.empty()){
		auto pr = q.front();
		q.pop();
		for(auto d: mv){
			int nx = pr.first + d.first;
			int ny = pr.second + d.second;

			if(mp.find({nx, ny}) == mp.end())
				continue;

			int ind = mp[{nx, ny}];
			if(vis[ind])
				continue;
			vis[ind] = 1;
			ans[ind] = ans[mp[pr]];
			q.push({nx, ny});
		}
	}

	for(int i = 0; i < n; i++){
		cout << ans[i].first << " " << ans[i].second << "\n";
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