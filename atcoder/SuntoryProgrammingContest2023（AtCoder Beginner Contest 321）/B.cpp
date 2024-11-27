

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
   int n, x;
   cin >> n >> x;
   vector<int> a(n - 1);
   for(int i = 0; i < n - 1; i++){
   	cin >> a[i];
   }  
   int sum = accumulate(all(a), 0ll);
   int mx = *max_element(all(a));
   int mn = *min_element(all(a));

   int req = max(0, x + mx + mn - sum);

   if(req <= mn) { 
   	 cout << "0\n";
   } else if(req > mn && req <= mx) { 
   	 cout << req << "\n";
   } else {
   	 cout << "-1\n";
   }

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