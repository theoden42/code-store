

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
    int n;
    cin >> n;
    vector<int> a(n);

    if(n == 3){
        cout << "1 2 3" << "\n";
        return;
    }

    int x = __builtin_popcount(n - 1);

    if(n % 4 == 1){

        int y = 1;
        while(y <= n){
            y *= 2;
        }
        a[0] = y;
        int count = 0;
        int xr1 = y;
        for(int i = 2; i < n; i += 2){
            a[i] = count++;
            xr1 ^= a[i];
        }

        int last = 1;
        int xr2 = 0;
        for(int i = 1; i < n; i += 2){
            a[i] = count++;
            xr2 ^= a[i];
            last = i;
        }   

        xr2 ^= a[last];
        a[last] = (xr1 ^ xr2);
        for(auto x: a){
            cout << x << " ";
        }
        cout << "\n";

    }
    else{

        int y = 1;
        while(y <= n){
            y *= 2;
        }
        a[0] = y;
        int count = 1;
        int xr1 = y;
        for(int i = 2; i < n; i += 2){
            a[i] = count++;
            xr1 ^= a[i];
        }

        int last = 1;
        int xr2 = 0;
        for(int i = 1; i < n; i += 2){
            a[i] = count++;
            xr2 ^= a[i];
            last = i;
        }   

        xr2 ^= a[last];
        a[last] = (xr1 ^ xr2);
        for(auto x: a){
            cout << x << " ";
        }
        cout << "\n";
    }

    int c1 = 0;
    int c2 = 0;
    for(int i = 0; i < n; i += 2){
        c1 ^= a[i];
    }
    for(int i = 1; i < n; i += 2){
        c2 ^= a[i];
    }

    debug(c1, c2);
    assert(c1 == c2);

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