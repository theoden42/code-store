

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

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    map<int,int> pnt;

    for(int i = 2; i <= n; i++){
    	int x;
    	cin >> x;
    	adj[x].push_back(i);
    	adj[i].push_back(x);
    	pnt[x]++;
    }

    vector<pair<int,int>> values(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> values[i].first >> values[i].second;
    }

    int count = 0;

    for(int i = 1; i <= n; i++){
    	if(pnt[i] == 0){
    		count++;
    	}
    }


    function<int(int, int)> dfs = 
    [&](int source, int parent)->int{

    	if(pnt[source] == 0){
    		return values[source].second;
    	}

    	int total = 0;
    	for(auto x: adj[source]){
    		if(x == parent)continue;
    		int temp = dfs(x, source);
    		total += temp;
    	}

    	debug(source, total);

    	if(total < values[source].first){
    		count++;
    		return values[source].second;
    	}
    	else{
    		return min(total, values[source].second);
    	}
    };

    dfs(1, -1);

    cout << count << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}