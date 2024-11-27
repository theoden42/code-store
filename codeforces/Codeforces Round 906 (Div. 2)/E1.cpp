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
    vector<vector<int>> endpoints(n + 1);
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        v[i] = {l, r};
        endpoints[l].push_back((i + 1));
        endpoints[r].push_back(-(i + 1));
    }

    vector<int> diff(n + 2);
    for(int i = 0; i < m; i++){
        diff[v[i].first] += 1;  
        diff[v[i].second + 1] -= 1;
    }
    for(int i = 1; i <= n + 1; i++){
        diff[i] = diff[i - 1] + diff[i];
    }
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(diff[i] == 0)
            count += 1;
    }

    vector<int> ones(n + 1);
    vector<int> twos(n + 1);
    for(int i = 1; i <= n; i++){
        ones[i] = ones[i - 1];
        twos[i] = twos[i - 1];
        ones[i] += (diff[i] == 1);
        twos[i] += (diff[i] == 2);
    }
    vector<int> mx_ones;
    for(int i = 0; i < m; i++){
        int one = ones[v[i].second] - ones[v[i].first - 1];
        mx_ones.push_back(one);
    }
    int mx = 0; 
    sort(all(mx_ones));
    if(mx_ones.size() >= 1){
        mx = max(mx, count + mx_ones.back());
    }
    if(mx_ones.size() >= 2){
        mx = max(mx, count + (mx_ones[mx_ones.size() - 1] + mx_ones[mx_ones.size() - 2]));
    }

    vector<int> maxl(n + 1, 0), minl(n + 1, 1e9), maxr(n + 1, 0), minr(n + 1, 1e9);
    multiset<int> st;
    for(int i = 1; i <= n; i++){
        for(auto x: endpoints[i]){
            if(x > 0){
                st.insert(v[x - 1].first);
            }
        }
        if(!st.empty()){
            minl[i] = *st.begin();
            maxl[i] = *st.rbegin();
        }
        for(auto x: endpoints[i]){
            if(x < 0){
                st.erase(st.find(v[-x - 1].first));
            }
        }
    }
    st.clear();
    for(int i = n; i >= 1; i--){
        for(auto x: endpoints[i]){
            if(x < 0){
                debug(i, x);
                st.insert(v[-x - 1].second);
            }
        }
        if(!st.empty()){
            minr[i] = *st.begin();
            maxr[i] = *st.rbegin();
        }
        for(auto x: endpoints[i]){
            if(x > 0){
                st.erase(st.find(v[x - 1].second));
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(diff[i] == 2){
            int leftboundone = minl[i];
            int rightboundone = maxr[i];
            int leftboundtwo = maxl[i];
            int rightboundtwo = minr[i];
            debug(leftboundone, rightboundone);
            int tone = ones[rightboundone] - ones[leftboundone - 1];
            int ttwo = twos[rightboundtwo] - twos[leftboundtwo - 1];
            int ans = tone + ttwo + count;
            mx = max(mx, ans);
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