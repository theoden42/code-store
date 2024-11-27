

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
    if(n == 1 && k == 1){
        cout << "YES\n";
        cout << "0\n";
        return;
    }
    if(k > n - 1 && n != 1){
    	cout << "NO\n";
    	return;
    }

    cout << "YES\n";
    vector<pair<int,int>> ans;

    if(k == 1){
        if(n == 2){
            cout << 1 << "\n";
            cout << "1 " << 2 << "\n";
            return;
        }
        for(int i = 1; i < n; i++){
            ans.push_back({i, i + 1});
        }
        ans.push_back({n, 1});
    }
    else{
        vector<int> deg(n + 1,0);
        int reqdeg = k;
        for(int i = 1; i <= n; i++){
            if(i > 1 && deg[i] == 0){
                ans.push_back({i - 1, i});
                deg[i]++;
                reqdeg++;
            }
            int x = deg[i];
            for(int j = 1; j <= reqdeg - x; j++){
                int vert = i + j;

                ans.push_back({i, vert});
                deg[i]++;
                deg[vert]++;
            }
            if(deg[i] == reqdeg)reqdeg--;
        }
        assert(reqdeg == 0);

    }
    cout << ans.size() << "\n";

    for(auto p: ans){
        cout << p.first << " " << p.second << "\n";
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