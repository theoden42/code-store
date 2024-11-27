

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
const ll INF = 1e18;
#define int long long


void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);

    int sum = 0;

    for(int i = 0; i < n; i++){
    	cin >> a[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> a[i].second;
    }

    for(int i = 0; i < n; i++){
        sum += (a[i].second - a[i].first + 1);
    }

    debug(a);

    if(sum < k){
        cout << "-1\n";
        return;
    }

    int s = 0;
    int x = 0;

    int mn = INF;


    for(int i = 0; i < n; i++){
        if(a[i].second - a[i].first + 1 == 1){
            x++;
        }
        else{
            s += (a[i].second - a[i].first + 1);
        }
        if(s + x < k){
            continue;
        }
        else if(s >= k){
            int val = a[i].second - (s - k) + 2 * (i + 1 - x);
            mn = min(mn, val);
            break;
        }
        else if(s + x >= k){
            int val = a[i].second + 2 * (i + 1 - x) + 2 * (k - s);
            mn = min(mn, val);
        }
    }

    cout << mn << "\n";
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