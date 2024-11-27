

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
    int l = 1 + rng() % 5;
    int r = l + 1 + rng() % 5;
    l *= 2;
    r *= 2;
    vector<int> v(r - l + 1);
    vector<int> t(r - l + 1);
    for(int i = 0; i < r - l + 1; i++){
    	v[i] = l + i;
    	t[i] = l + i;
    }

    debug(v);

    do{
    	int f = 1;
    	for(int i = 0; i < r - l + 1; i++){
    		if(gcd(v[i], t[i]) != 1)
    			f = 0;
    	}
    	if(f){
    		debug(t);
    		debug("next");
    		return;
    	}
    } while(next_permutation(all(t)));

    debug(-1);
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