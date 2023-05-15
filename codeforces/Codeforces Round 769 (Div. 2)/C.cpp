

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

vector<int> getbits(int a){
	vector<int> b(33, 0);
	int k = 0;
	while(a != 0){
		b[k++] = (a & 1);
		a >>= 1;
	}
	return b;
}

void solve() {
	int a, b;
	cin >> a >> b;

	int mn = b - a;

	int x = a;
	int y = b;

	while(x < b){
		if((x | b) == b){
			mn = min(mn, x - a + 1);
		}
		x++;
	}
	while(y < 2 * b){
		if((y | a) == y){
			mn = min(mn, y - b + 1);
		}
		y++;
	}

	cout << mn << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}