

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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> adj(n + 1);
    vector<int> req(n + 1);
    for(int i = 1; i <= n; i++){
    	req[i] = s[i - 1] - '0';
    }
    vector<int> in(n + 1);
    for(int i = 1; i <= n; i++) {
    	int a;
    	cin >> a;
    	adj[i] = a;
    	in[a] += 1;
    }
    queue<int> q;
    vector<int> vis(n + 1);
    for(int i = 1; i <= n; i++){
    	if(in[i] == 0){
    		q.push(i);
    		vis[i] = 1;
    	}
    }
    vector<int> ans;    
    while(!q.empty()){
    	auto node = q.front();
    	q.pop();
    	if(req[node]){     
    		req[node] += 1;
    		req[node] %= 2;
    		req[adj[node]] += 1;
    		req[adj[node]] %= 2;
            ans.push_back(node);
    	}
        auto x = adj[node];
        in[x] -= 1;
        if(in[x] == 0){
            q.push(x);
            vis[x] = 1;
        }
    }  
    // debug(req, vis);

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vector<int> cycle;
            int x = i;
            int c = 0;  
            while(!vis[x]){
                vis[x] = 1;
                cycle.push_back(x);
                if(req[x])
                    c += 1;
                x = adj[x]; 
            }
            // debug(cycle, c);
            if(c & 1){
                cout << "-1\n";return;
            }
            if(c == 0)
                continue;
            vector<int> p1, p2;
            map<int,int> mp;
            for(auto x: cycle){
                vis[x] = 0;
                if(req[x])
                    mp[x] += 1;
            }
            int ind = 0;
            // debug(req);
            for(int j = ind; j < cycle.size(); j++){
                if(req[cycle[j]]){
                    ind = j;
                    break;
                }
            }
            x = cycle[ind];
            // debug(x);
            while(!vis[x]){
                vis[x] = 1;
                if(req[x]){
                    p1.push_back(x);
                    req[x] += 1;
                    req[x] %= 2;    
                    req[adj[x]] += 1;
                    req[adj[x]] %= 2;
                }
                x = adj[x];
            }
            for(auto x: cycle){
                vis[x] = 0;
                if(mp[x])
                    req[x] = 1;
                else 
                    req[x] = 0;
            }

            for(int j = ind + 1; j < cycle.size(); j++){
                if(req[cycle[j]]){
                    ind = j;
                    break;
                }
            }
            x = cycle[ind];
            // debug(x);
            while(!vis[x]){
                vis[x] = 1;
                if(req[x]){
                    p2.push_back(x);
                    req[x] += 1;
                    req[x] %= 2;
                    req[adj[x]] += 1;
                    req[adj[x]] %= 2;
                }
                x = adj[x];
            }   
            // debug(p1, p2);
            if(p1.size() > p2.size())
                swap(p1, p2);
            for(auto x: p1){
                ans.push_back(x);
            }
        }
    }
    // debug(ans);
    cout << ans.size() << "\n";
    for(auto a: ans){
        cout << a << " ";
    }
    cout << "\n";
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