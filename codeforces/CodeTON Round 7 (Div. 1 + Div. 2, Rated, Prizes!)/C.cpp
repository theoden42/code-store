

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
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    vector<int> ans(n);
    multiset<pair<int,int>> mst;
    for(int i = 0; i < n; ++i){
    	cin >> a[i];
    	mst.insert({-a[i], i});
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }
    sort(all(b));
    for(int i = x - 1; i >= 0; i--){
    	auto [_, ind] = *mst.begin();
    	mst.erase(mst.begin());
    	ans[ind] = b[i];
    }

    for(int i = n - 1; i >= x; i--){
    	auto [_, ind] = *mst.begin();
    	mst.erase(mst.begin());
    	ans[ind] = b[i];
    }

    int count = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] > ans[i])
    		count += 1;
    }


    if(count == x){
    	cout << "YES\n";
    	for(auto e: ans)
    		cout << e << " ";
    	cout << "\n";
    } else {
    	cout << "NO\n";
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