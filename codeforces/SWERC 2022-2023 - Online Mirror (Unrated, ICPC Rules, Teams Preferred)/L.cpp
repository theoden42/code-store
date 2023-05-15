

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == '+')p++;
    }



    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
    	int a, b;
        cin >> a >> b;

        if(a == b){
            if(p == n - p)cout << "YES\n";
            else cout << "NO\n";
            continue;
        }

    	int x = (2 * p - n) * a;
    	int y = (a - b);
    	if(x % y != 0){
    		cout << "NO\n";
    		continue;
    	}
        int z = x / y;

        int x1 = p;
        int x2 = n - p;

        if(z <= 0 && x2 >= -1 * z){
            cout << "YES\n";
        }
        else if(z > 0 && x1 >= z){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";            
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