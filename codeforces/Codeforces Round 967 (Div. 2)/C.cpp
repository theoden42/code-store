

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
    set<pair<int,int>> edges;

    auto query = [&](int a, int b){
    	cout << "? " << a << " " << b << endl;
    	int x;
    	cin >> x;
        if(x == -1)
            exit(0);
    	return x;
    };

    vector<int> vis(n + 1);
    function<void(int,int)> build_edge = [&](int a, int b){
    	int v = query(a, b);
    	if(v == a){
    		edges.insert({min(a,b), max(b,a)});
            vis[a] = 1;
            vis[b] = 1;
    		return;
    	}
        if(!vis[v])
    	   build_edge(a, v);
        if(!vis[b])
    	   build_edge(v, b);
    };

    for(int i = 2; i <= n; i++){
        if(!vis[i])
            build_edge(1, i);
    }
    assert(edges.size() == n - 1);
    cout << "! ";
    for(auto [a, b]: edges){
    	cout << a << " " << b << " ";
    }
    cout << endl;
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