

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
    int n, m;
    cin >> n >> m;
    vector<int> k(n);


    for(int i = 0; i < n; ++i){
    	cin >> k[i];
    }
    sort(all(k));


    for(int i = 0; i < m; i++){
    	int a, b, c;
    	cin >> a >> b >> c;
    	ll x = 4 * a * c;


    	if(x <= 0){
    		cout << "NO\n";
    		continue;
    	}
    	int l = 0;
    	int u = n - 1;
    	int ans = k[0];
    	int mn = abs(k[0] - b);

    	while(l <= u){
    		int mid = l + (u - l) / 2;
    		int dif = abs(k[mid] - b);
    		if(dif < mn){
    			mn = dif;
    			ans = k[mid];
    		}

    		if(k[mid] < b){
    			l = mid + 1;
    		}
    		else{
    			u = mid - 1;
    		}
    	}

    	if(mn * mn < x){
    		cout << "YES\n";
    		cout << ans << "\n";
    	}
    	else{
    		cout << "NO\n";
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