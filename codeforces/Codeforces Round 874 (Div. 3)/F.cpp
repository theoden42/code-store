

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

ll modinverse(ll a, ll b=MOD){
	return binpow(a, b - 2) % MOD;
}


void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a;
	map<int,int> mp;

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(mp[x] == 0){
			a.push_back(x);
		}
		mp[x]++;
	}

	int count = 0;
	sort(all(a));

	n = a.size();

	vector<int> prefix(n + 1);
	prefix[0] = 1;
	for(int i = 1; i <= n; i++){
		prefix[i] = (prefix[i - 1] * mp[a[i - 1]]) % MOD;
	}


	for(int i = 0; i < n; i++){
		// debug(count);
		int ind = i + m - 1;
		if(ind >= n || a[ind] - a[i] >= m){
			// debug(a[ind], a[i]);
			continue;
		}
		else{
			count += (prefix[ind + 1] * modinverse(prefix[i])) % MOD;
			count %= MOD;
		}
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