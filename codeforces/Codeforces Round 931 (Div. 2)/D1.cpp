

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

vector<int> getbit(int v){
	vector<int> b(64);
	for(int i = 0; i < 64; i++){
		if(v >> i & 1ll)
			b[63 - i] = 1;
	}
	return b;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> curr;
    curr.push_back(n);

	int val = curr.back();
	if((val ^ m) <= val){
		cout << 1 << "\n";
		cout << n << " " << m << "\n";
		return;
	}

	int ind = 63; 
	for(int i = 63; i >= 0; i--){
		if(!(n >> i & 1ll) && (m >> i & 1ll)){
			ind = i;
			break;
		}	
	}

	vector<int> sz;
	for(int i = 63; i > ind; i--){
		if((n >> i & 1ll)){
			sz.push_back(i);
		}
	}
	if(sz.size() == 1){
		cout << "-1\n";
		return;
	}


	int ind2 = sz.back();
	int num = 0;
	for(int i = 0; i < ind; i++){
		if((n >> i & 1ll) != (m >> i & 1ll)){
			num |= (1ll << i);
		}
	}

	// debug(ind, ind2);

	num |= (1ll << ind);
	num |= (1ll << ind2);

	// debug(getbit(num));

	curr.push_back(n ^ num);
	n ^= num;

	curr.push_back(m);

	cout << 2 << "\n";
	for(auto v: curr){
		cout << v << " ";
	}

	// for(auto v: curr){
	// 	debug(getbit(v));
	// }

	cout << "\n";
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