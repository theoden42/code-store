

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
    vector<int> x(2 * n);
    for(int i = 0; i < 2 * n; i++){
    	cin >> x[i];
    }
    vector<int> smaller(2 * n, -1);
    for(int i = 0; i < 2 * n; i++){
    	int nxt = (i + n) % (2 * n);
    	if(x[i] < x[nxt]){
    		smaller[i] = 0;
    	} else if(x[i] > x[nxt]){
    		smaller[i] = 1;
    	} else {
    		smaller[i] = -1;
    	}
    }

    // debug(smaller);
    int ind = -1;
    for(int i = 0; i < 2 * n; i++){
    	int prv = (i - 1 + 2 * n);
    	prv %= (2 * n);	
    	if((smaller[prv] == 1 || smaller[prv] == -1) && smaller[i] == 0){
    		ind = i;
    		break;
    	}
    }
    if(ind == -1){
    	cout << "-1\n";
    	return;
    }

    ind += (n / 2);
    ind %= (2 * n);

    auto check = [&](int ind)->int{
    	vector<int> a(n), b(n);
	    for(int i = 0; i < n; i++){
	    	a[i] = x[ind];
	    	ind += 1;
	    	ind %= (2 * n);
	    }
	    for(int i = 0; i < n; i++){
	    	b[i] = x[ind];
	    	ind += 1;
	    	ind %= (2 * n);
	    }

	  	reverse(all(b));
	  	if(b != a){
	  		return 1e9;
	  	}

		reverse(all(b));
	  	for(int i = 0; i < n / 2; i++){
	  		if(a[i] >= b[i]){
	  			return 1e9;
	  		}
	  	}
	  	for(int i = n / 2 + 1; i < n; i++){
	  		if(a[i] <= b[i]){
	  			return 1e9;
	  		}
	  	}
	  	return ind;
    };


   	int ans = check(ind);

   	if(ans == 1e9){
   		cout << "-1\n";
   	} else{
   		cout << ans << "\n";
   	}
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
         cout << "Case #" << t << ": ";
        solve();
    }
}