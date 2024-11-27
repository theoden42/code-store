/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <debug.h>

using namespace std;

vector<int> recoverDeadPods(int n,
 vector<vector<int>> connections, 
 vector<vector<int>> queries){
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < connections.size(); i++){
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }

    int count = 0;
    map<int,int> regions;
    map<int,multiset<int>> pods;
    vector<int> vis(n + 1);

    function<void(int)> dfs = [&](int source){
        regions[source] = count;
        vis[source] = 1;
        for(auto x : adj[source]) if(!vis[x]){
            dfs(x);
        }
    };
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            count++;
        }
    }
    for(int i = 1; i <= n; i++){
        pods[regions[i]].insert(i);
    }
    debug(pods[0]);
    vector<int> ans;
    for(int i = 0; i < queries.size(); i++){
        int t = queries[i][0];
        int id = queries[i][1];
        if(t == 1){
            int r = regions[id];
            if(pods[r].empty()){
                ans.push_back(-1);
                continue;
            }
            ans.push_back(*pods[r].begin());
        } else {
            int r = regions[id];
            pods[r].erase(id);
        }
    }

    return ans;
}

int main() {
    vector<int> ans = recoverDeadPods(1, {{1, 2}}, {{1, 2}});
    debug(ans);
}