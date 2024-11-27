

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

vector<int> fac(MAX_N + 1);
vector<int> inv(MAX_N + 1);

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}

ll modinverse(ll a, ll b=MOD){
	return binpow(a, b - 2) % MOD;
}

void pre(){
	fac[0] = 1;
	inv[0] = 1;
	for(int i = 1; i < MAX_N; i++){
		fac[i] = (i * fac[i - 1]);
		fac[i] %= MOD;
		inv[i] = modinverse(fac[i]);
	}
}

int ncr(int n, int r){
	int ans = fac[n];
	ans *= inv[r];
	ans %= MOD;
	ans *= inv[n - r];
	ans %= MOD;
	return ans;
}

void solve() {
    int n;
    cin >> n;
    n *= 2;
    vector<int> p(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	cin >> p[i];
    	if(p[i] != 0){
    		mp[p[i]] += 1;
    	}
    }
    for(int i = 0; i < n; i++){
    	if(p[i] == 0 && p[i + 1] != 0){
    		swap(p[i], p[i + 1]);
    	}
    }

    int leftcomp = 0, rightcomp = 0, fix = 0;
    for(int i = 0; i < n; i += 2){
    	if(p[i] != 0 && p[i + 1] != 0){
    		if(p[i] <= n / 2 && p[i + 1] <= n / 2){
    			leftcomp++;
    		} else if(p[i] >= n / 2 && p[i + 1] >= n / 2){
    			rightcomp++;
    		} else{
    			fix += 1;
    		}
    	}
    }


    int left = 0, right = 0;
    for(int i = 1; i <= n / 2; i++){
    	if(mp.find(i) == mp.end())
    		left += 1;
    } 
    for(int i = n / 2 + 1; i <= n; i++){
    	if(mp.find(i) == mp.end()){
    		right += 1;
    	}
    }
    // debug(left, right);
    int ans = 1;
    for(int i = 0; i < n; i++){
    	if(p[i] != 0){
    		if(p[i] <= n / 2){
    			ans *= right;
    			ans %= MOD;
    			right -= 1;
    		} else {
    			ans *= left;
    			ans %= MOD;
    			left -= 1;
    		}
    	}
    }
    // debug(left, right);
    assert(left == right);
    ans *= fac[right];
    ans %= MOD;
    ans *= fac[left];
    ans %= MOD;
    ans *= binpow(2, left);
    ans %= MOD;
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    pre();
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}