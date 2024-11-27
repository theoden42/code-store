

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
    string a, b;
    cin >> a >> b;
    int n = a.size();
    string tempa, tempb;
    tempa = a;
    tempb = b;

    int ind1 = n - 1;
    int ind2 = n - 1;

    int flag = 0;

    while(ind1 >= 0 && ind2 >= 0){
        if(a[ind1] == '1' && b[ind2] == '1'){
            ind1 -= 1;
            ind2 -= 1;
            // continue;
        }
        else if(a[ind1] == '0' && b[ind2] == '0'){
            flag = 1;
            break;
        }
        else if(a[ind1] == '0'){
            int ind = -1;
            for(int j = ind1; j >= 0; j--){
                if(a[j] == '1'){
                    ind = j;
                    break;
                }
            }
            if(ind == -1){
                break;
            }
            for(int j = ind; j <= ind1; j++){
                a[j] = '1';
            }
            ind1 -= 1;
            ind2 -= 1;
        }
        else {
            int ind = -1;
            for(int j = ind2; j >= 0; j--){
                if(b[j] == '1'){
                    ind = j;
                    break;
                }
            }
            if(ind == -1){
                break;
            }
            for(int j = ind; j <= ind2; j++){
                b[j] = '1';
            }
            ind1 -= 1;
            ind2 -= 1;
        }
    }

    if(flag){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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