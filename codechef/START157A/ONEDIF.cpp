

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

int lcm(int a, int b){
	int x = a * b;
	x /= gcd(a, b);
	return x;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), fac(m + 1);
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    	for(int j = 1; j * j <= v[i]; j++) if(v[i] % j == 0){
    		fac[j] += 1;
    		if(j * j != v[i]){
    			fac[v[i] / j] += 1; 
    		}
    	}
    }

    vector<int> left;
    for(int i = 1; i <= m; i++){
    	if(fac[i] == 0){
    		left.push_back(i);	
    	}
    }
    vector<int> lcmd;
    int lm = 1;
    for(auto l: left){
    	lm = lcm(lm, l);
    	if(lm > m)
    		break;
    	lcmd.push_back(lm);
    }
    if(left.size() == 0){
    	cout << m + 1 << "\n";
    	return;
    }
    debug(left, lcmd);
   	int curr = left[0];
    for(int i = 0; i < n; i++){
    	int lm = 1;
    	int flag = 1;
    	for(int j = 1; j * j <= v[i]; j++) if(v[i] % j == 0){
    		if(j * j == v[i]){
    			if(fac[j] == 1){
    				lm = lcm(lm, j);
    			}
    		} else {
    			if(fac[j] == 1){
    				lm = lcm(lm, j);
    			} 
    			if(fac[v[i] / j] == 1){
    				lm = lcm(lm, v[i] / j);
    			}
    		}

    	}

        debug(lm);

    	int lb = 0;
    	int ub = lcmd.size() - 1;
    	int ans = -1;
    	while(lb <= ub){
    		int mid = lb + (ub - lb) / 2;
    		int nlm = lcm(lm, lcmd[mid]);
    		if(nlm <= m){
    			ans = mid;	
    			lb = mid + 1;
    		} else{
    			ub = mid - 1;	
    		}
    	}
        if(ans == -1)
            continue;
    	int nmx = (ans + 1 == (int)left.size() ? m + 1: left[ans + 1]);
    	curr = max(curr, nmx);	
    }


    cout << curr << "\n";
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