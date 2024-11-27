

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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), lg(n + 1), pre(n + 1), lgsum(n + 1);
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    sort(all(a));


    for(int i = 1; i <= n; i++){
    	int cnt = 0;
    	int x = a[i];
    	while(x != 0){
    		cnt += 1;
    		x /= 2;
    	}
    	lg[i] = cnt;
    	pre[i] = cnt;
    	pre[i] += pre[i - 1];
    	lgsum[i] = i * cnt - (pre[i]);
    }

    int ans = 0;
    for(int j = 1; j <= n; j++){
    	if(lgsum[j] > k){
    		vector<int> temp;
    		temp.push_back(0);
    		for(int i = 1; i < j; i++){
    			int t = binpow(2, (lg[j - 1] - lg[i]));
    			a[i] *= t;
    			temp.push_back(a[i]);
    			k -= (lg[j - 1] - lg[i]);
    		}
    		sort(all(temp));
    		// debug(temp);
    		int cnt = k / (j - 1);
    		int rem = k % (j - 1);

    		for(int i = 1; i <= n; i++){
    			int pw = 1;
    			if(i - 1 < rem){
    				pw = binpow(2, cnt + 1);
    			} else if(i <= j - 1){
    				pw = binpow(2, cnt);
    			} 
    			if(i < j)
    				pw *= temp[i];
    			else 
    				pw *= a[i];
    			pw %= MOD;
    			ans += pw;
    			ans %= MOD;
    		}
    		break;
    	} else if(j == n){
    		vector<int> temp;
    		temp.push_back(0);
    		for(int i = 1; i <= n; i++){
    			int t = binpow(2, lg[n] - lg[i]);
    			a[i] *= t;
    			temp.push_back(a[i]);
    			k -= (lg[n] - lg[i]);
    		}
    		sort(all(temp));
    		int cnt = k / n;
    		int rem = k % n;
    		for(int i = 1; i <= n; i++){
    			int pw = 1;
    			if(i < rem + 1){
    				pw = binpow(2, cnt + 1);
    			} else {
    				pw = binpow(2, cnt);
    			}

    			pw *= temp[i];
    			pw %= MOD;
    			ans += pw;
    			ans %= MOD;
    		}
    		break;
    	}
    }

    cout << ans << "\n";
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