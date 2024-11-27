

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

vector<vector<int>> adj;

void solve() {
    int m;
    cin >> m;
    adj.resize(m + 4);
    for(int j = 1; j <= m; j++){
        string x;
        cin >> x;
        int w = 0, i = 0, n = 0;
        for(auto ch: x){
            if(ch == 'w')w++;
            if(ch == 'i')i++;
            if(ch == 'n')n++;
        }
        if(w > 1){
            for(int i = 2; i <= w; i++)
                adj[j].push_back(m + 1);
        }
        if(i > 1){
            for(int k = 2; k <= i; k++)
                adj[j].push_back(m + 2);
        }
        if(n > 1){
            for(int i = 2; i <= n; i++)
                adj[j].push_back(m + 3);
        }

        if(w < 1){
            adj[m + 1].push_back(j);
        }
        if(i < 1){
            adj[m + 1].push_back(j);
        }
        if(n < 1){
            adj[m + 1].push_back(j);
        }
    }

    

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