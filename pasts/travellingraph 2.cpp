#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int n, m;
    cin >> n >> m;
    if(m == 0){
        cout << n - 1 << "\n";
        return;
    }
    vector<vector<int>> adj(n, vector<int> (n, -1));
    for(int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	adj[x-1][y-1] = 0;
    	adj[y-1][x-1] = 0;
    }
    //implementing djikstra
    for(int i = 1; i < n; i++){
    	if(adj[i][i-1] == -1 && adj[i-1][i] == -1){
    		adj[i][i-1] = 1;
    		adj[i-1][i] = 1;
    	}
    }

    vector<int> dist(n, INF);
    dist[0] = 0;
    vector<int> vis(n, 0);
    for(int j = 0; j < n-1; j++){
        int md = INT_MAX;
    	int u = 0;
    	for(int i = 0; i < n; i++){
    		if(md >= dist[i] && !vis[i]){
    			u = i;
                md = dist[i];
    		}
    	}
        vis[u] = 1;
    	for(int i = 0; i < n; i++){
    		if(!vis[i] && dist[i]  <= INF && adj[i][u] != -1 && dist[i] > dist[u] + adj[u][i]){
                dist[i] = dist[u] + adj[u][i];
            }
        }	
    }
    cout << dist[n - 1] << '\n';
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