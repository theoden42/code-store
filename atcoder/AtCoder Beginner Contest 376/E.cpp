

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
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
    	cin >> vp[i].first;
    }
    for(int i = 0; i < n; i++){
    	cin >> vp[i].second;
    }
    sort(all(vp));
    // debug(vp);
    multiset<int> mst;
    int sum = 0;
    for(int i = 0; i < k; i++){
    	mst.insert(vp[i].second);
    	sum += vp[i].second;
    }
    int val = vp[k - 1].first * sum;
    for(int i = k; i < n; i++){
    	mst.insert(vp[i].second);
    	sum += vp[i].second;
    	auto it = prev(mst.end(),1);
    	sum -= *it;
    	mst.erase(it);
    	int temp = vp[i].first * sum;
    	val = min(val, temp);
    }
    cout << val << "\n";
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