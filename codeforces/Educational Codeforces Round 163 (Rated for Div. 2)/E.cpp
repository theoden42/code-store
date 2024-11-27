

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

    // if(k >= n){
    //     for(int i = 0; i < n; i++){
    //         cout << i + 1 << " \n"[i == n - 1];
    //     }
    //     cout << n << "\n";
    //     for(int i = 0; i < n; i++){
    //         cout << i + 1 << " \n"[i == n - 1];
    //     }
    //     return;
    // }

    int len = k;
    vector<int> ans(n);

    int count = 1;
    for(int i = 0; i < n; i += k){
        int j = min(n - 1, i + k - 1);
        int left = min(n - 1, i + k / 2 - 1);
        int t = left;
        while(t >= i && t >= 0){
            ans[t] = count++;
            t -= 1;
        }  
        while(j > left){
            ans[j] = count++;
            j -= 1;
        }

    }    

    int num = (n + len - 1) / len;
    for(int i = 0; i < n; i++){
        cout << ans[i] << " \n"[i == n - 1];
    } 

    cout << (n + k - 1) / k << "\n";
    for(int i = 0; i < n; i++){
        int x = (i / k);
        cout << x + 1 << " \n"[i == n - 1];
    }


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