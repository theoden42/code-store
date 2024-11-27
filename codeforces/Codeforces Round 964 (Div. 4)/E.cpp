

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

int count3(int x){
	int s = 0;
	while(x != 0){
		x /= 3;
		s += 1;
	}
	return s;
}

void solve() {
    int l, r;
    cin >> l >> r;
    if(r - l <= 4){
    	int sum = 0;
    	for(int x = l; x <= r; x++){
    		int cn = count3(x);
    		sum += cn;
    		if(x == l)
    			sum += cn;
    	}
    	cout << sum << "\n";
    	return;
    }

    int x = count3(l);
    int lst = l;
    int ans = x;
    while(lst <= r){
    	int rightbnd = 1;
    	for(int i = 0; i < x; i++){
    		rightbnd *= 3;
    	}
    	int right = min(r + 1, rightbnd);
    	int no = right - lst;
    	ans += no * x;
    	lst = right;
    	x += 1;
    }
    cout << ans << "\n";
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