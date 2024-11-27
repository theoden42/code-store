

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> v(m);
    vector<int> flag(n + 1);
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        v[i] = {l, r};
        flag[l] += 1;
    }

    vector<int> diff(n + 2);
    for(int i = 0; i < m; i++){
        diff[v[i].first] += 1;  
        diff[v[i].second + 1] -= 1;
    }
    for(int i = 0; i <= n + 1; i++){
        diff[i] = diff[i - 1] + diff[i];
    }
    vector<int> ones(n + 1), twos(n + 1);
    for(int i = 1; i <= n; i++){
        ones[i] = ones[i - 1];
        twos[i] = twos[i - 1];
        ones[i] += (diff[i] == 1);
        twos[i] += (diff[i] == 2); 
    }
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(diff[i] == 0)
            count += 1;
    }
    int mx = 0; 
    for(int i = 1; i <= n; i++){
        if(diff[i] == 1 && flag[i] >= 1){
            int countzero = 1; 
            int start = 0;
            int j = i;
            while(j <= n && diff[j] <= 2){
                if(countzero == 2 && flag[j] >= 1){
                    break;
                }
                if(flag[j] >= 1){
                    countzero += 1;
                }
                if(diff[j] == 0){
                    start += 1;
                }
                j += 1;
            }
            int sz = j - i + count - start;
            i = j - 1;
            mx = max(mx, sz);
        } else if(diff[i] == 2){
            int start = 0;
            int j = i;
            while(j <= n && diff[j] <= 2){
                if(flag[j] >= 1){
                    break;  
                }
                if(diff[j] == 0){
                    start += 1;
                }
                j += 1;
            }
            int sz = j - i + count - start;
            i = j - 1;
            mx = max(mx, sz);
        }
    }

    cout << mx << "\n";

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