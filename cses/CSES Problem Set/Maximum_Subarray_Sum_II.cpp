

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

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<ll> v(n);
	vector<ll> p(n + 1), s(n + 1);



	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	p[0] = 0;
	for(int i = 1; i <= n; i++){
		p[i] = p[i - 1] + v[i - 1]; 
	}

	s[0] = 0;
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + v[n - i];
	}


	multiset<ll> mst;
	ll mn = 1e18;

	for(int i = n - a; i >= n - b; i--){
		mst.insert(s[i]);
	}

	for(int i = 0; i <= n - a; i++){	
		ll px = p[i];
		ll val = *mst.begin();
		ll sm = px + val;
		mn = min(mn, sm);

		if(i != n - a){
			mst.erase(s[n - a - i]);
			mst.insert(s[max(0, n - b - i - 1)]);
		}

	}

	ll sum = accumulate(all(v), 0ll);
	cout << sum - mn << "\n";

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