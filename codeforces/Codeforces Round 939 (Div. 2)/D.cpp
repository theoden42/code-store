

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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    vector<pair<int,int>> vp;
    function<int(int, int)> ans = [&](int l, int r){
    	if(r < l)
    		return 0;
    	int sz = r - l + 1;
    	if(sz == 1){
            if(a[l] == 0){
                vp.push_back({l, l});
            }
    		return max(1, a[l]);
    	}
    	for(int x = l; x <= r; x++){
    		if(a[x] >= sz * sz){
    			return a[x] + ans(l, x - 1) + ans(x + 1, r);
    		}
    	}
        int flag = 1;
        for(int k = l; k <= r; k++){
            if(a[k] == 0)
                flag = 0;
        }
        if(flag){
            vp.push_back({l, r});
        } else {
            vp.push_back({l, r});
            vp.push_back({l, r});
        }
        for(int j = r; j >= l; j--)
            vp.push_back({j, r});
    	return sz * sz;
    };

    int fin = ans(0, n - 1);
    cout << fin << " " << vp.size() << "\n";
    for(auto [l, r]: vp){
        cout << l + 1 << " " << r + 1 << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}