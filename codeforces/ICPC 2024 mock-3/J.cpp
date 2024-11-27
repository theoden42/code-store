

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
    int d, c, r;
    cin >> d >> c >> r;
    vector<int> a, b;
    for(int i = 0; i < c; i++){
    	int x;
    	cin >> x;
    	a.push_back(x);
    }
    for(int i = 0; i < r; i++){
    	int x;
    	cin >> x;
    	b.push_back(x);
    }
    int i = 0;
    int j = 0;
    int curr = d;
    int count = 0;
    while(i < c || j < r){
    	if(i < c && a[i] <= curr){
    		curr -= a[i];
    		i++;
    		count += 1;
    		continue;
    	} 
    	if(j < r){
    		curr += b[j];
    		j++;
    		count += 1;
    		continue;
    	}
    	break;
    }

    cout << count << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}