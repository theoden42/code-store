
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
vector<bool> vis(1e5 + 5, false);
map<int,int> mp;
int n, m;
vector<vector<int>> adj(1e5 + 5);

int dfs(int vert, int cats){
    // cout << vert << " " << cats << "\n";
    int count = 0;
    vis[vert] = true;
    if(mp[vert] == 1)
        cats += 1;
    else{
        cats = 0;
    }
    if(cats > m){
        return 0;
    }
	for(auto& x: adj[vert]){
        if(!vis[x]){
            count++;
        }
    }
    if(count == 0){
        return 1;
    }
    int sum = 0;
    for(auto& x: adj[vert]){
        if(!vis[x]){
            sum += dfs(x, cats);
        }
    }
    return sum;
}

void solve() {
 cin >> n >> m;
 int x;
 for(int i = 1; i <= n; i++){
 	cin >> x;
    if(x == 1){
        mp[i] = 1;
    }
}   
 for(int i = 0; i < n - 1; i++){
 	int a, b;
 	cin >> a >> b;
 	adj[a].push_back(b);
 	adj[b].push_back(a);
 }
int ans = dfs(1, 0);
    cout << ans << "\n";
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