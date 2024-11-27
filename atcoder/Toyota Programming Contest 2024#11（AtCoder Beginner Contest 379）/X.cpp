

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
    vector<int> a(3), b(3), c(3);
    for(int i = 0; i < 3; i++){
    	cin >> a[i] >> b[i] >> c[i];
    }
    vector<int> perm = {0, 1, 2};
    auto better = [&](int i, int j){
    	if(a[j] < a[i] || b[j] < b[i] || c[j] < c[i])
    		return false;
    	return (a[j] > a[i] || b[j] > b[i] || c[j] > c[i]);	
    };
    do {
    	if(better(perm[0], perm[1]) && better(perm[1], perm[2])){
    		cout << "yes\n";
    		return;
    	}
    } while(next_permutation(all(perm)));
    cout << "no\n";
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