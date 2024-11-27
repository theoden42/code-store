

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
        	ans = (ans * a);
        }
        a = (a * a);
        b = b >> 1; 
    }
    return (ans);
}

int getdigit(int n, int k){
	vector<int> dig;
	while(n != 0){
		dig.push_back(n % 10);
		n /= 10;
	}
	reverse(all(dig));
	return dig[k];
}

void solve() {
	vector<int> pref(19);
	int sum = 0;
	for(int i = 1; i < 19; i++){
		int num = binpow(10, i) - 1;
		pref[i] = num - sum;
		sum += pref[i];
	}
	int q;
	cin >> q;
	for(int i = 1; i <= q; i++){
		int k;
		cin >> k;
		int sum = 0;
		for(int i = 1; i < 19; i++){
			sum += i * pref[i];
			if(sum >= k){
				sum -= i * pref[i];
				int add = (k - sum - 1) / i;
				int num = binpow(10, i - 1) + add;
				int ans = getdigit(num, (k - sum - 1) % i);
				cout << ans << "\n";
				break;
			} 
		}
	}

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