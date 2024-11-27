

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
    int n, k;
    cin >> n >> k;
    int l = 0;
    int r = 1;
    int ans = 0;
    for(int i = 0; i < k; i++){
    	char c;int x;
    	cin >> c >> x;
    	x -= 1;
    	if(c == 'L'){
    		int tl = l;
    		int cnt = 0;
    		while(tl != r && tl != x){
    			tl += 1;
    			tl %= n;
    			cnt += 1;
    		}
    		if(tl == x){
    			l = tl;
    			ans += cnt;
    			continue;
    		}
    		tl = l;
    		cnt = 0;
    		while(tl != r && tl != x){
    			tl -= 1;
    			tl += n;
    			tl %= n;
    			cnt += 1;
    		}
    		ans += cnt;
    		l = tl;
    	} else {
    		int tr = r;
    		int cnt = 0;
    		while(tr != l && tr != x){
    			tr += 1;
    			cnt += 1;
    			tr %= n;
    		}
    		if(tr == x){
    			ans += cnt;
    			r = tr;
    			continue;
    		}
    		tr = r;
    		cnt = 0;
    		while(tr != l && tr != x){
    			tr -= 1;
    			tr += n;
    			tr %= n;
    			cnt += 1;
    		}
    		ans += cnt;
    		r = tr;
    	}
    }

    cout << ans << "\n";
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