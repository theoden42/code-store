

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
const ll MOD = 998244353;
const ll INF = 1e9;

#define int long long


vector<int> factorise(int n){
    vector<int> factors;
    int x = n;

    for(int i = 2; i * i <= n; i++){

        if(x % i == 0)factors.push_back(i);

        while(x % i == 0){
            x /= i;
        }
    }

    if(x != 1){
        factors.push_back(x);
    }
    return factors;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    for(int i = 0; i < n - 1; i++){
    	if((a[i] % a[i + 1]) != 0){
    		cout << "0\n";
    		return;
    	}
    }

    int count = 1;

    for(int i = 1; i < n; i++){
    	int r = a[i - 1] / a[i];
    	int x = m / a[i];

    	if(r == 1){
    		int times = m / a[i];
    		count = (count * times) % MOD;
    		continue;
    	}
    	vector<int> facs = factorise(r);	

    	int pie = 0;
    	int mask = (1 << (int)facs.size());

    	for(int j = 1; j < mask; j++){
    		int prod = 1;
    		for(int k = 0; k < facs.size(); k++){
    			if(j >> k & 1){
    				prod *= facs[k];
    			}
    		}

            int num = x / prod;

    		if(__builtin_popcount(j) & 1){
    			pie += num;
    		}
    		else{
    			pie -= num;
    		}
    	}

    	count *= (x - pie);
    	count %= MOD;
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
