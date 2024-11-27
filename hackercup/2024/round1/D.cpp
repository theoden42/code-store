

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

void brute(int l, int d, int L){
	int count = 0;
	for(int i = 0; i < (1 << l); i++){
		int c1 = 0, c0 = 0;
		int mn = 0;
		int flag = 1;
		int curr = 0;
		for(int j = 0; j < l; j++){
			if(i >> j & 1) {
				c1 += 1;
				curr += 1;
			}
			else {
				c0 += 1;
				curr -= 1;
			}
			if(curr > mn + L){
				flag = 0;
			}
		}
		if(curr != -d){
			flag = 0;
		}
		count += flag;	
		if(flag){
			for(int j = 0; j < l; j++){
				cout << ((i >> j & 1) ? 1 : -1)<< " ";
			}
			cout << endl;
		}
	}

	debug(count);	
}

void solve() {
	for(int i = 2; i < 10; i++){
		brute(i, 2, 2);
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