

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
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];

    int ans = -1;

    x += 1;
    for(int i = 30; i >= 0; i--){

        int count = 0;
        for(int ind = 0; ind < a.size(); ind++){
            if(a[ind] >> i & 1){
                count += 1;
            }
        }

        // debug(a, count);

        if(count & 1){
            if(x >> i & 1){
                continue;
            } else {
                break;
            }
        } else {
            vector<int> nw;
            int ind = 0;    
            int flag = 1;
            for(int j = 0; j < a.size(); j++){
                if(a[j] >> i & 1){
                    if(flag){
                        nw.push_back(a[j]);
                        flag = 0;
                    } else {
                        nw[nw.size() - 1] = (nw.back() ^ a[j]);
                        flag = 1;
                    }
                } else {
                    if(flag){
                        nw.push_back(a[j]);
                    } else {
                        nw[nw.size() - 1] = (nw.back() ^ a[j]);
                    }
                }
            }

            if(x >> i & 1){
                ans = max(ans, (int)nw.size());
            } else {
                a.assign(all(nw));
            }
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