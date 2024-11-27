

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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(k));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < k; j++){
    		cin >> a[i][j];
    	}
    }

    map<vector<int>, int> mp;

    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n; j++){
    		vector<int> third(k);
    		for(int l = 0; l < k; l++){
    			third[l] = (3 - (a[i][l] + a[j][l]) % 3) % 3;
    		}
    		mp[third]++;
    	}
    } 

    ll count = 0;

    for(int i = 0; i < n; i++){
    	int x = mp[a[i]];
    	if(x > 0){
    		ll temp = (1ll * x * (x - 1)) / 2;
    		count += temp;
    	}
    }

    cout << count << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}