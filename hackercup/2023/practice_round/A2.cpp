

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

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;

   	if(b <= a) { 
   		ans = 2 * (c / b) - 1;
   	} else if(b >= 2 * a){
   		ans = (c / a);
   	} else if(c < a){
        ans = 0;
    } else { 
   		int temp = 2 * (c / b) - 1;
   		int left = c % b;
   		if(temp > 0 && left >= a){
   			temp += 2;
   		}
   		ans = temp;

        int buns = 0, patty = 0;
        c -= a;
        buns += 2;
        patty += 1;
        temp = (c / b);
        buns += 2 * temp;
        patty += 2 * temp;

        left = c % b;
        if(left >= a){
            patty += 1;
            buns += 2;
        }
        temp = min(buns - 1, patty);
        ans = max(ans, temp);
   	}

   	cout << max(0ll, ans) << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}