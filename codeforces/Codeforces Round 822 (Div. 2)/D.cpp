

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }

    int left = k - 1;
    int right = k + 1;

    int leftsum = 0;
    int rightsum = 0;
    int curr = a[k];

    while(true){

    	int t = curr;

    	for(int i = left; i > 0; i--){
    		if(leftsum + a[i] + curr < 0){
    			left = i;
    			break;
    		}
    		else if(leftsum + a[i] > 0){
    			leftsum += a[i];	
    			curr += leftsum;
    			leftsum = 0;
    		}
    		else{
    			leftsum += a[i];
    		}
    		left = i - 1;
    	}

    	for(int j = right; j <= n; j++){
    		if(rightsum + a[j] + curr < 0){
    			right = j;
    			break;
    		}
    		else if(rightsum + a[j] > 0){
    			rightsum += a[j];
    			curr += rightsum;
    			rightsum = 0;
    		}
    		else{
    			rightsum += a[j];
    		}
    		right = j + 1;
    	}

    	if(left == 0 || right == n + 1){
    		cout << "YES\n";
            return;
    	}
    	else if(t != curr)continue;
    	else{
    		break;
    	}
    }	

    cout << "NO\n";
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