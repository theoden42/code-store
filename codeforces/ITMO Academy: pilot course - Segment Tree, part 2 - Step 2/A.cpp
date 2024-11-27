

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

struct SegTree{

	int size;
	vector<ll> operations;
	vector<ll> values;

	ll iden_operation = 1;
	ll iden_element = 0;

	ll modify_op(ll a, ll b){
		return (a * b) % MOD;
	}

	ll calc_op(ll a, ll b){
		return (a + b) % MOD;
	}

	void apply_mod_operation(ll& a, ll b){
		a = modify_op(a, b);
	}

	void init(int n){	
		size = 1;
		while(size < n)size *= 2;
		operations.assign(2 * size, iden_operation);
		values.assign(2 * size, iden_element);
	}

	void modify(int l, int r, int v, int x, int lx, int rx){
		if(lx >= r || l >= rx)return;
		if(lx >= l && rx <= r){
			apply_mod_operation(values[x], v);
			return;
		}
		int m = (lx + rx) / 2;
		modify(l, r, v, 2 * x + 1, lx, m);
		modify(l, r, v, 2 * x + 2, m, rx);
		values[x] = calc_op((values[2 * x + 1], values[2 * x + 2]));
		apply_mod_operation(values[x], operations[x]);
	}

	void modify(int l, int r, int v){
		modify(l, r, v, 0, 0, size);
	}

	ll calc(int l, int r, int x, int lx, int rx){
		if(lx >= r || l >= rx)return iden_element;
		if(lx >= l && rx <= r){
			return values[x];
		}

		int m = (lx + rx) / 2;
		auto m1 = calc(l, r, 2 * x + 1, lx, m);
		auto m2 = calc(l, r, 2 * x + 2, m, rx);


		auto res = calc_op(m1, m2);
		apply_mod_operation(res, opearations);
		return res;
	}

	ll calc(int l, int r){
		return calc(l, r, 0, 0, size);
	}

};

void solve() {
	int n, m;
    cin >> n >> m;

    SegTree st;
    st.init(n);

    for(int i = 1; i <= m; i++){
    	int t;
    	cin >> t;
    	if(t == 1){
    		int l, r, v;
    		cin >> l >> r >> v;
    		st.modify(l, r, v);
    	}
    	else{
    		int l, r;
    		cin >> l >> r;
    		cout << st.calc(l, r) << "\n";
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