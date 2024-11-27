

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
    multiset<int> mst;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	a[i] = x;
    	mst.insert(i);
    }
    for(int i = 32; i >= 0; i--)if(k >> i & 1ll){
    	vector<int> v;
    	for(auto x: mst){
    		if(!(a[x] >> i & 1ll)){
    			v.push_back(x);
    		}
    	}
    	for(auto x: v){
    		mst.erase(mst.find(x));
    	}
    }
    if(mst.empty()){
    	cout << "NO\n";
    	return;
    }
    int val = a[*mst.begin()];
    for(auto x: mst){
    	val &= a[x];
    }
    if(val != k){
    	cout << "NO\n";return;
    }
    cout << "YES\n";
    cout << mst.size() << "\n";
    for(auto v: mst){
    	cout << v + 1 << " ";
    }
    cout << "\n";
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