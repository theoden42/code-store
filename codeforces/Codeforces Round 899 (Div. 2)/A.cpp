

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

    int bn = n;
    while(true){
    	int f = 1;
    	int val = bn;
    	int j = n - 1; 
    	vector<int> ans(n);
    	while(j >= 0){
    		if(a[j] == val){
    			ans[j] = val - 1;
    			val -= 2;
    		} else {
    			ans[j] = val;
    			val -= 1;
    		}
    		j -= 1;
    	}
    	for(int i = 0; i < n; i++){
    		if(ans[i] <= 0){
    			f = 0;
    			break;
    		}
    	}

    	if(f){
    		cout << bn << "\n";
    		break;
    	} else {
    		bn += 1;
    	}
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