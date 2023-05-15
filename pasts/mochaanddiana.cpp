
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


int parent1[MAX_N];
int parent2[MAX_N];
int size1[MAX_N];
int size2[MAX_N];


int getparent(int source, int n){
    if(source == 1){
        return parent1[n] == n ? n : getparent(1, parent1[n]);
    }   
    else{
        return parent2[n] == n ? n : getparent(2, parent2[n]);
    }
}   

void merge(int source, int a, int b){
    int x1 = getparent(source, a);
    int x2 = getparent(source, b);
    if(source == 1){
        if(size1[x1] > size1[x2]){
            parent1[x2] = x1;
            size1[x1] += size1[x2];
        }
        else{
            parent1[x1] = x2;
            size1[x2] += size1[x1];
        }
    }
    else{
        if(size2[x1] > size2[x2]){
            parent2[x2] = x1;
            size2[x1] += size2[x2];
        }
        else{
            parent2[x1] = x2;
            size2[x2] += size1[x1];
        }

    }

}

void dfs(int source, vector<vector<int>>& g, vector<int>& vis, vector<int>& comp){
    vis[source] = 1;
    comp.push_back(source);
    for(auto& x: g[source]){
        if(!vis[x]){
            dfs(x, g, vis, comp);
        }
    }
}


void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> g1(n + 1);
    vector<vector<int>> g2(n + 1);



    for(int i = 0; i < m1; i++){
        int u, v;
        cin >> u >> v;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }

    for(int i = 0; i < m2; i++){
        int u, v;
        cin >> u >> v;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }


    for(int i = 1; i <= n; i++){
        parent1[i] = i;
        parent2[i] = i;
        size1[i] = 1;
        size2[i] = 1;
    }

    vector<pair<int,int>> ans;

    vector<int> vis1(n + 1, 0);
    vector<int> vis2(n + 1, 0);

    for(int i = 1; i <= n; i++){
        if(!vis1[i]){
            vector<int> comp;
            dfs(i, g1, vis1, comp);
            debug(comp);
            for(int i = 1; i < comp.size(); i++){
                merge(1, comp[0], comp[i]);
            }
        }
        if(!vis2[i]){
            vector<int> comp;
            dfs(i, g2, vis2, comp);
            for(int i = 1; i < comp.size(); i++){
                merge(2, comp[0], comp[i]);
            }
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)continue;
            if(getparent(1, i) != getparent(1, j) && getparent(2, i) != getparent(2, j)){
                ans.push_back({i, j});
                merge(1, i, j);
                merge(2, i, j);
            }
        }
    }

    cout << ans.size() << "\n";
    for(auto& x: ans){
        cout << x.first << " " << x.second << "\n";
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