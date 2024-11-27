

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
    vector<pair<int,int>> a(n);
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	a[i] = {x, i};
    }

    sort(all(a));
    int sum = 0;
    for(int i = 0; i < n; i++){
    	sum += a[i].first;
    }
    int j = 0;
    for(int i = 0; i < n; i++){
    	j = max(j, i);
    	while(j < n && a[j].first <= a[i].first){
    		sum -= a[j].first;
    		j += 1;
    	}
    	ans[a[i].second] = sum;
    }

    for(auto e: ans) { 
        cout << e << " ";
    }
    cout << "\n";
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