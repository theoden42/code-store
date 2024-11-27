

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

const int N = 1e5 + 10;

 
void solve() {
    int n, m;
    cin >> n >> m;
    set<pair<int,int>> st;
    for(int i = 0; i < m; i++){
    	int l, r;
    	cin >> l >> r;
    	st.insert({l, r});	
    }

    int q;
    cin >> q;
    vector<int> query(q);
    for(int i = 0; i < q; i++){
        cin >> query[i];
    }

    int l = 0;
    int u = q;
    int ans = INF;

    auto check = [&](int value){

        vector<int> atemp(n);
        for(int i = 0; i < value; i++){
            int ind = query[i] - 1;
            atemp[ind] = 1;
        }

        vector<int> prefix(n + 1);
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + atemp[i - 1];
        }

        // debug(prefix);

        // debug(value, atemp);

        for(auto x: st){
            int l = x.first;
            int r = x.second;
            int len = r - l + 1;
            int sum = prefix[r] - prefix[l - 1];
            // debug(x, sum);
            if(sum > len - sum)return true;
        }

        return false;

    };

    while(l <= u){
        int mid = (l + u) / 2;
        if(check(mid)){
            ans = mid;
            u = mid - 1;
        }
        else{
            l = mid + 1;    
        }
    }

    if(ans == INF){
        cout << "-1\n";
        return;
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