
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
vector<int> level(MAX_N, 0);
vector<int> g[MAX_N];
vector<bool> vis(MAX_N, false);
vector<int> par(MAX_N, -1);

void bfs(){
	queue<int> q;
	q.push(1);
	level[1] = 0;
	while(!q.empty()){
		int cur_v = q.front();
		// cout << cur_v << "\n";
		q.pop();
		vis[cur_v] = true;
		for(auto& y: g[cur_v]){
			if(!vis[y]){
				par[y] = cur_v;
				level[y] = level[cur_v] + 1;
				q.push(y);
			}
		}
	}
}

void solve() {
    int n;
    cin >> n;
   	for(int i = 0; i < n - 1; i++){
   		int x, y;
   		cin >> x >> y;
   		g[x].push_back(y);
   		g[y].push_back(x);
   	}
   	bfs();
   	vector<int> ele(n, 0);
   	for(int i = 0; i < n; i++){
   		cin >> ele[i];
   	}
   	// for(int i = 1; i <= n; i++){
   	// 	cout << par[i] << "\n";
   	// }
   	for(int i = 1; i < n; i++){
   		if(level[ele[i]] < level[ele[i - 1]]){
   			// cout << ele[i] << " ";
   			cout << "NO" << "\n";
   			return;
   		}
   	}
  	map<int,int> mp;
  	mp[1] = 0;
  	for(int i = 0; i < n; i++){
  		mp[ele[i]] = i;
  	}

  	for(int i = 1; i < n; i++){
  		if(mp[par[ele[i]]] < mp[par[ele[i - 1]]]){
  			cout << "NO" << "\n";
  			return;
  		}
  	}
  	cout << "YES" << "\n";
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