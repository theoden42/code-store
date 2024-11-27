
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define int long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;

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

ll modinverse(ll a, ll b = MOD){
	return binpow(a, b - 2) % MOD;
}



void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> ele(n);
	for(int i = 0; i < n; i++){
		cin >> ele[i];
	}

	vector<int> v;
	int zr = 0;
	for(int i = 0; i < n; i++){
		if(ele[i] != 0){
			v.push_back(ele[i]);
		}
		else{
			zr++;
		}
	}

	sort(all(v));

	map<int,int> mp;

	for(int i = 1; i <= m; i++){
		mp[i] = 0;
	}

	for(int i = 0; i < v.size(); i++){
		if(mp.find(v[i]) == mp.end()){
			mp[v[i]] = i + 1; 
		}

	}

	int ans = 0;


	auto prob = [&](int val){
		
		int p = 0;
		p = mp[val] == 0 ? (binpow(m - 1, zr) * modinverse(m, zr)) % MOD: 1;
		int nsmall = (int)(upper_bound(all(v), val) - v.begin());
		int req = k - nsmall;

		int b = 0;

		if(req > zr){
			b = 0;
		}
		else{
			
		}


	}



	for(int i = 1; i <= m; ++i){
		int val = i;
		int ind = mp[i];


		if(ind == 0){
			auto it =	upper_bound(all(v), val);
			int pos = (int)(it - v.begin()); // number of elements smaller than given element
			if(pos > k ){
				continue;
			}
			else{
				int req = (k - pos);
				int a1 = binpow(val - 1, req);
				int a2 = binpow(m, req);
				int a3 = (1 - (a1 * modinverse(a2)) % MOD + MOD) % MOD;

				int b1 = binpow(m - 1, req);
				int b2 = binpow(m, req);
				int b3 = (b1 * modinverse(b2)) % MOD;

				b3 = (b3 + a3) % MOD;

				ans = (ans + (b3 * val) % MOD) % MOD;
			}

			continue;
		}

		if(ind > k){
			continue;
		}
		else{
			int req = (k + 1 - ind);
			int a1 = binpow(val - 1, req);
			int a2 = binpow(m, req);
			int a3 = (1 - (a1 * modinverse(a2)) % MOD + MOD) % MOD;

			ans = (ans + (a3 * val) % MOD) % MOD;

		}
	}
	cout << ans << "\n";


}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}