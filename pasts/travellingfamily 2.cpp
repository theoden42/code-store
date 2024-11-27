
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void bfsn(int src, vector<vector<int>>& g, vector<int>& vis, vector<int>& dist){
	queue<int> q;
	q.push(src);
	dist[src] = 0;
	while(!q.empty()){
		int x = (q.front());
		vis[x] = 1;
		q.pop();
		for(auto& y: g[x]){
			if(!vis[y]){
				dist[y] = dist[x] + 1;
				q.push(y);
			}
		}
	}
}

void solve() {
    int n, m, x, y, c1, c2, c3;
    cin >> n >> m >> x >> y >> c1 >> c2 >> c3;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }
    vector<int> vis1(n + 1, false);
    vector<int> vis2(n + 1, false);
    vector<int> dist1(n + 1, -1);
    vector<int> dist2(n + 1, -1);
    bfsn(x, g, vis1, dist1);
    bfsn(y, g, vis2, dist2);
    if(dist1[n] == -1 || dist2[n] == -1){
    	cout << "-1\n";
    	return;
    }

    int db = dist1[y];
    ll s1 = 1ll * c1 * dist1[n] * 1ll * c2 + dist2[n];
    ll s2 = 1ll * db * c1 + c3 * dist2[n];
    ll s3 = 1ll * db * c2 + c3 * dist1[n];
    cout << min({s1, s2, s3})<< "\n";	

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