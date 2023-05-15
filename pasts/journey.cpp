
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

vector<int> g[100001];
vector<int> vis(100001, 0);
double ans = 0;

void dfs(int source, int parent, int dis, double p){
	debug(source, parent, p, g[source]);
	if(g[source].size() == 1 && parent != -1){
		ans += p * dis;
		return;
	}
	vis[source] = 1;
	for(auto& x: g[source]){
		if(!vis[x]){
			double temp = (parent != -1 ? p  / (double)(g[source].size() - 1) : p / (double)(g[source].size()));
			dfs(x, source, dis + 1, temp);
		}
	}
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1, -1, 0, 1);
    cout << setprecision(10)<< ans << "\n";
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