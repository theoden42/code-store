

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
    vector<int> a(n), b(n);

    map<int,vector<int>> mp;


    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }


    for(int i = 0; i < n; i++){
    	mp[a[i]].push_back(b[i]);
    }

    for(int i = 2; i <= 2 * n; i++){
    	for(int j = 1; j * j <= i; j++){
    		if(i % j != 0)continue;
    		int f1 = j;
    		int f2 = i / j;

    		vector<int> a = 

    	}
    }

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