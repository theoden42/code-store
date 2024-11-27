

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
    vector<pair<int,int>> q;
    q.push_back({n, 1});
    int sum = 0;

    while(!q.empty()){
    	map<int,int> mp;
    	for(auto [val, time]: q){
    		int x1 = val / 2ll;
    		int x2 = (val + 1) / 2ll;
    		sum += val * time;

    		mp[x1] += time;
    		mp[x2] += time;
    	}
    	vector<pair<int,int>> nw;
    	for(auto [num, f]: mp){
    		if(num >= 2){
    			nw.push_back({num, f});
    		}
    	}
    	q.assign(all(nw));
    }

    cout << sum << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}