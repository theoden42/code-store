#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 998244353;

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

ll modinverse(ll a){
	return binpow(a, MOD - 2) % MOD;
}

ll mdiv(ll a, ll b) {
	return (a%MOD * modinverse(b)%MOD)%MOD;
}

ll mmul(ll a, ll b) {
	return (a%MOD * b%MOD)%MOD;
}

vector<vector<ll>> adj;
vector<pair<ll, ll>> nc;

ll get(ll a) {
	return mdiv(mmul(a, a-1), 2);
}

ll dfs(ll node, ll par) {

	ll x = nc[node].first - nc[node].second;
	ll ans;
	if(x%2) {
		ans = max(1LL, x * get(x-1));
	}
	else {
		ans = max(1LL, get(x));
	}
	//cout << node << " " << ans << endl;
	for(auto &x : adj[node]) {
		if(x == par) continue;
		ans = mmul(ans, dfs(x, node));
		//cout << x << ". " << ans << endl;
	}

	return max(1LL, ans);
}

void dfs1(int node, int par) {

		nc[node].first = (ll) adj[node].size();
		nc[node].first--;

		for(auto &x : adj[node]) {
			if(x == par) continue;
			ll s = (ll) adj[x].size();
			s--;
			if(s%2) {
				nc[node].second++;
				// cout << x << endl;
			}

			dfs1(x, node);
		}

		return;
}

void solve() {
	ll n; cin >> n;
	adj.resize(n);
	nc.resize(n);
	int x, y;
	for(int i = 0; i < n-1; i++) {
		cin >> x >> y;
		adj[--x].push_back(--y);
		adj[y].push_back(x);
	}
	

	dfs1(0, -1);
	nc[0].first++;

	// for(auto &c : nc) {
	// 	cout << c.first << " " << c.second << endl;
	// }

	cout << dfs(0, -1);
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}