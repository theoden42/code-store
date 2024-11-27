

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
    int n, cq;
    cin >> n >> cq;
    int sumsq = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
    	int l;
    	cin >> l;
    	sumsq += l * l;
    	sum += l;
    }


    // debug(sum, sumsq);

    int low = 0;
    int high = 1e9;


  	auto check = [&](int w, int c){
        // debug(w);
  		int sumval = 0;	
  		sumval += w * w;
  		if(sumval > c)
  			return 1;
  		if(sumval > (c + 3) / 4)
  			return 1;
  		sumval *= 4;
  		if(sumval > (c + n - 1) / n)
  			return 1;
  		sumval *= n;

  		int b = 4 * sum * w;
  		if(b > c)
  			return 1;
  		int cval = sumsq;
        
  		sumval += b;
  		sumval += cval;

  		if(sumval > c)
  			return 1;
  		else if(sumval == c)
  			return 0;
  		else
  			return -1;

  	};

    while(low <= high){
    	int mid = low + (high - low) / 2 ;
    	int v = check(mid, cq);

    	if(v == -1){
    		low = mid + 1;
    	}
    	else if(v == 1){
    		high = mid - 1;
    	}
    	else{
    		cout << mid << "\n";
    		return;
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