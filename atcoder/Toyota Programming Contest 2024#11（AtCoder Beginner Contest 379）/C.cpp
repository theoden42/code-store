

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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> vp(m);
    int sum = 0;
    for(int i = 0; i < m; i++){
    	cin >> vp[i].first;
    }
    for(int i = 0; i < m; i++){
        cin >> vp[i].second;
        sum += vp[i].second;;
    }
    sort(all(vp));

    if(sum != n){
    	cout << "-1\n";
    	return;
    }	
    int ans = 0;
    int lst = 0;
    int curr = 0;
    for(int i = 0; i < m; i++){
        auto [x, a] = vp[i];
        if(x != lst + 1){
            int left = x - lst - 1;
            if(curr < left){
                cout << "-1\n";
                return;
            } else {
                ans += (left * (left + 1)) / 2;
                curr -= left;   
            }
            ans += curr * (left + 1);
            curr += a - 1;
        } else {
            ans += curr;
            curr += a - 1;
        }
        lst = x;
    }   
    if(lst != n){
        int left = n - lst;
        if(curr < left){
            cout << "-1\n";
            return;
        } else {
            ans += (left * (left + 1)) / 2;
        }
    }
    cout << ans << "\n";
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