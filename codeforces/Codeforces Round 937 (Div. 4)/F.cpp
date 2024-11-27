

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
    int a, b, c;
    cin >> a >> b >> c;
    int n = a + b + c;

    if(n == 1 && c == 1){
    	cout << "0\n";
    	return;
    }

    vector<vector<int>> adj(n);
    queue<int> q;
    q.push(0);

    int count = 1;
    while(!q.empty()){
    	auto nd = q.front();
    	q.pop();
    	if(a > 0){
    		if(count >= n - 1){
    			cout << "-1\n";
    			return;
    		}
    		adj[nd].push_back(count);
    		adj[count].push_back(nd);
    		q.push(count);
    		count += 1;
    		adj[nd].push_back(count);
    		adj[count].push_back(nd);
    		q.push(count);
    		count += 1;
    		a -= 1;
    	} else if(b > 0){
    		if(count >= n){
    			cout << "-1\n";
    			return;
    		}
    		adj[nd].push_back(count);
    		adj[count].push_back(nd);
    		q.push(count);
    		count += 1;
    		b -= 1;
    	}
    }


    int x = 0;
    for(int i = 1; i < n; i++){
    	if(adj[i].size() == 1)
    		x += 1;
    }

    if(x != c){
    	cout << "-1\n";
    	return;
    }

    vector<int> h(n);
    function<void(int,int,int)> 
    dfs = [&](int source, int parent, int ht){
    	h[source] = ht;
    	for(auto nd: adj[source]) if(nd != parent){
    		dfs(nd, source, ht + 1);
    	}
    };

    dfs(0, -1, 0);

    int mx = *max_element(all(h));

    cout << mx << "\n";

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