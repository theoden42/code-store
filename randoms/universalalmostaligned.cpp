

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
    int n;
    cin >> n;
    vector<string> v(2 * n);
    for(int i = 0; i < 2 * n; i++){
        cin >> v[i];
    }  

    debug(v);
 
    vector<int> dep(n + 1);
    int t = 0;
    for(auto s: v){
        if(s[0] == '-'){
            int x = s[1] - '0';
            dep[x] = t++;
        }
    }


    stack<int> st1, st2;
    vector<int> ans(n + 1);
    int i = 0;
    for(auto s: v){
        debug(s);
        if(s[0] == '+'){
            int v = s[1] - '0';
            if(st1.empty()){
                st1.push(v);
                ans[i] = 0;
                continue;
            }
            if(st2.empty()){
                st2.push(v);
                ans[i] = 1;
                continue;
            }
            auto x1 = st1.top();
            auto x2 = st2.top();
            if(dep[x1] > dep[v]){
                st1.push(v);
                ans[i] = 0;
            } else if(dep[x2] > dep[v]){
                st2.push(v);
                ans[i] = 1;
            } else {
                cout << "*\n";
                return;
            }
        } else {
            int v = s[1] - '0';

            auto x1 = st1.empty() ? 0 : st1.top();
            auto x2 = st2.empty() ? 0 : st2.top();
            if(x1 == v){
                st1.pop();
            } else {
                st2.pop();
            }
        }
        i += 1;
    }

    debug(ans);

    for(int i = 1; i <= n; i++){
        if(ans[i]){
            cout << "G";
        } else {
            cout << "S";
        }
    }

    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}