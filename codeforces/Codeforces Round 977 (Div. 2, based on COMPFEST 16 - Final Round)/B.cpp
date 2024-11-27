

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
    vector<int> a(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	mp[a[i]] += 1;
    }
    sort(all(a));
    map<int,int> rem;
    int mx = 0;
    for(int i = 0; i < n; i++){
    	if(mp.find(i) != mp.end()){
    		rem[i % x] += mp[i] - 1;
    		mx += 1;
    	} else if(rem[i % x] > 0){
    		rem[i % x] -= 1;
    		mx += 1;
    	} else {
    		break;
    	}
    }
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