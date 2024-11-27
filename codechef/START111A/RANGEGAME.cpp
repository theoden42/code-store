

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

vector<int> ndiv(int n, int p){
	int mx = 1;
	int count = 0;
	vector<int> ansv(64);
	for(int i = 0; i <= 64; i++){
		if(n / mx < p){
			break;
		}
		mx *= p;
		count += 1;
	}
	int ans = 0;
	int sum = 0;
	for(int i = count; i >= 1; i--){
		int nd = (n / mx);
		ansv[i] = nd - ans;
		ans += nd - ans;
		mx /= p;
	}

	return ansv;
}

int totdiv(int n, int p){
	return (n / p);
}

void solve() {
	int l, r, p;
	cin >> l >> r >> p;
	vector<int> a = ndiv(r, p);
	vector<int> b = ndiv(l - 1, p);
	for(int i = 0; i < 64; i++){
		a[i] -= b[i];
	}
	int xr = 0;
	for(int i = 1; i < 64; i++){
		xr ^= ((a[i] & 1) ? i : 0);
	}
	if(xr){
		cout << "First\n";
	} else {
		cout << "Second\n";
	}
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