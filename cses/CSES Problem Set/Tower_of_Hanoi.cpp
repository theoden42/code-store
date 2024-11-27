

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
const ll MOD = 1e18 + 7;
const ll INF = 1e9;

vector<vector<int>> ans;

void recur(int n, int source, int dest){
    if(n == 1){
        ans.push_back({source, dest});
        return;
    }

    int middle = 0;
    for(int i = 1; i <= 3; i++){
        if(i != source && i != dest){
            middle = i;
        }
    }

    recur(n - 1, source, middle);
    ans.push_back({source, dest});
    recur(n - 1, middle, dest);
}


void solve(){
    int n;
    cin >> n;
    recur(n, 1, 3);
    cout << ans.size() << "\n";
    for(auto v: ans){
        cout << v[0] << " " << v[1] << "\n";
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