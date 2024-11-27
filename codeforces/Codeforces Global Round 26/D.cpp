

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

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ind = -1;
    for(int i = 0; i < n; i++){
        if(s[i] != 'a'){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        cout << n - 1 << "\n";
        return;
    }
    int ans_count = 0;
    int a_count = ind;
    string nw = s.substr(ind, n - ind);
    vector<int> z = z_function(nw);
    vector<int> nota;
    for(int i = 0; i < nw.size(); i++){
        if(nw[i] != 'a'){
            nota.push_back(i);
        }
    }
    for(int l = 1; l <= nw.size(); l++){
        int mna = a_count;
        int flag = 1;
        int lst = l;
        for(int i = l; i < nw.size(); i++){
            auto it = lower_bound(all(nota), i);
            if(it == nota.end())
                break;
            i = *it;
            int curr = i - lst;
            // debug(lst, curr);
            lst = i + l;
            // debug(i, lst);
            if(nw[i] != s[ind]){
                flag = 0;
                break;
            } else if(z[i] < l){
                flag = 0;
                break;
            } else{
                mna = min(mna, curr);
                i += l - 1;
            }
        }
        // debug(l, flag, mna);
        if(flag){
            ans_count += 1 + mna;
        }
        // debug(ans_count);
    }
    cout << ans_count << "\n";
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