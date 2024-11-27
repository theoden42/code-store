

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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    // first position of (( should be before the first position of ))
    // if one is filled and one is empty-> no
    // last position of (( should be before the last position of ))
    // correct starting and ending is required;
    multiset<int> open, close;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == '(' && s[i + 1] == s[i]){
            open.insert(i);
        }
        if(s[i] == ')' && s[i + 1] == s[i]){
            close.insert(i);
        }
    }

    auto change = [&](int ind){

        if(ind < n - 1 && s[ind] == s[ind + 1]){
            if(s[ind] == '('){
                open.erase(ind);
            } else {
                close.erase(ind);       
            }
        }
        if(ind > 0 && s[ind] == s[ind - 1]){
            if(s[ind] == '('){
                open.erase(ind - 1);
            } else {
                close.erase(ind - 1);
            }
        }

        if(s[ind] == '('){
            s[ind] = ')';
        } else {
            s[ind] = '(';
        }

        if(ind < n - 1){
            if(s[ind] == s[ind + 1]){
                if(s[ind] == '('){
                    open.insert(ind);
                } else {
                    close.insert(ind);
                }
            }
        }
        if(ind > 0 && s[ind] == s[ind - 1]){
            if(s[ind] == '('){
                open.insert(ind - 1);
            } else {
                close.insert(ind - 1);
            }
        }

    };

    for(int i = 1; i <= q; i++){
        int ind;
        cin >> ind;
        ind--;
        change(ind);
        if(n & 1 || s[0] == ')' || s[n - 1] == '('){
            cout << "NO\n";
            continue;
        }
        if(open.empty() && close.empty()){
            cout << "YES\n";
            continue;
        } else if(open.empty()){
            cout << "NO\n";
            continue;
        } else if(close.empty()){
            cout << "NO\n";
            continue;
        }
        int fo = *(open.begin());
        int lo = *(--open.end());
        int fc = *(close.begin());
        int lc = *(--close.end());

        if(fc < fo || lc < lo){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }

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