

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

vector<int> fac(1e6 + 5);
vector<int> invfac(1e6 + 5);

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

ll modinverse(ll a, ll b){
	return binpow(a, b - 2) % MOD;
}

void preprocess(){
	fac[0] = 1;
	invfac[0] = 1;
	for(int i = 1; i < 1e6 + 5; i++){
		fac[i] = (fac[i - 1] * i) % MOD;
		invfac[i] = modinverse(fac[i], MOD);
	}
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    }

    if(n == 1){
    	cout << 1 << "\n";
    	return;
    }

    debug(v);
    vector<vector<int>> movable(n, vector<int>(m, 0));
    for(int j = 0; j < m; j++){
    	movable[n - 1][j] = v[n - 1][j] - '0';
    }
    for(int i = n - 2; i >= 1; i--){
    	int count = 0;
    	for(int j = 0; j < m; j++){
    		if(v[i][j] == '1'){
    			count += 1;
    		}
    	}
    	for(int j = 0; j < m; j++){
    		movable[i][j] = v[i][j] - '0';
    	}
    	if(count <= 1){
    		continue;
    	}
    	int zero = 0, one = 0;
    	vector<int> ind;
    	for(int j = 0; j < m; j++){
    		if(movable[i + 1][j]){
    			if(v[i][j] == '0'){
    				zero += 1;
    				ind.push_back(j);
    			}
    			else {
    				one += 1;
    			}
    		}
    	}
    	if(one >= 1){
    		for(auto in: ind){
    			movable[i][in] = 1;
    		}
    	}
    }

    int fnzero = 0, fnones = 0;
    for(int j = 0; j < m; j++){
    	if(movable[1][j]){
    		if(v[0][j] == '0')
    			fnzero += 1;
    		else 
    			fnones += 1;
    	}
    }


    int val = fac[fnzero + fnones];
    debug(val, fnzero, fnones, invfac[fnzero], invfac[fnones]);
    val *= invfac[fnzero];
    val %= MOD;
    val *= invfac[fnones];
    val %= MOD;

    cout << val << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    preprocess();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}