
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e18 + 7;
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

void solve() {
	ll n;
	cin >> n;
	vector<ll> indexes;
	int k = 0;

	while(n != 0){
		if((n & 1) == 1){
			indexes.push_back(k);
		}
		k++;
		n = n >> 1;
	}

	vector<ll> ans;
	ans.push_back(0);

	int x = indexes.size();

	for(int i = 0; i < x; i++){
		vector<ll> temp;
		for(int j = 0; j < (int)ans.size(); j++){
			temp.push_back(ans[j] + binpow(2, indexes[i]));
		}

		for(int j = 0; j < (int)temp.size(); j++){
			ans.push_back(temp[j]);
		}

	}

	for(auto& x: ans){
		cout << x << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}