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
    vector<int> a(n);
    map<int,int> freq;

    
    for(int i = 0; i < n; ++i){
    	cin >> a[i];
    	freq[a[i]]++;
    }

    ll count = 0;

    for(int i = 0; i < n; i++){
    	int temp = 0;
    	for(int j = 2; j * j <= a[i]; j++){
    		if(a[i] % j == 0){
    			int f1 = j;
    			int f2 = a[i] / j;
    			if(f1 == f2){
    				int c = a[i] / f1;
    				if(c * a[i] <= 1e6)
    					temp += freq[c * a[i]] * freq[f1];
    			}
    			else{
    				int c1 = a[i] / f1;
    				int c2 = a[i] / f2;
    				if(c1 * a[i] <= 1e6)
    					temp += freq[c1 * a[i]] * freq[f1];

    				if(c2 * a[i] <= 1e6)
    					temp += freq[c2 * a[i]] * freq[f2];
    			}
    		}
    	}
    	if(a[i] == 1){
    		temp += (freq[1] - 1) * (freq[1] - 2);
    	}else{
    		temp += (freq[a[i]] - 1) * (freq[a[i]] - 2);
    		temp += freq[1] * freq[a[i] * a[i]];
    	}
    	count += temp;
    }

    cout << count << "\n";
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