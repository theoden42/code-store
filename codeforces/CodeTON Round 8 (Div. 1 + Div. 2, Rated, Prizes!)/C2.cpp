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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x);
    for(int i = 0; i < x; i++){
        cin >> a[i];
        a[i] -= 1;
    }

    sort(all(a));

    vector<int> vals;

    int vert = n;
    int ans = 0;
    for(int i = 0; i < x; i++){
        int rem = (a[(i + 1) % x] - a[i] - 1);
        rem += n;
        rem %= n;

        if(rem == 1)
            ans += 1;

        vert -= rem;

        if(rem != 1)
            vals.push_back(rem);
    }


    ans += vert - 2;


    sort(all(vals), [&](int& a, int& b){
        if((a & 1) && (b & 1)){
            return (a < b);
        } else if(a &, 1){
            return true;
        } else if(b & 1){
            return false;
        } else {
            return (a < b);
        }
    });

    
    for(auto v: vals){
        if(y <= 0)
            break;

        int req = (v / 2);
        if(y >= req && (v & 1)){
            ans += 2 * req + 1;
            y -= req;
        } else if(y >= req){ 
            ans += 2 * req;
            y -= req;
        } else { 
            ans += 2 * y;
            y = 0;
        }
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