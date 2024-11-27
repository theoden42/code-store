

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
    vector<string> s(2);
    cin >> s[0];
    cin >> s[1];
    string x = "";
    int ind = n - 1;

    int row = 0;
    int col = 0;

    for(int i = 0; i <= n; i++){
        x += s[row][col];
        if(row == 1){
            col += 1;
        } else if(col == n - 1){
            row += 1;   
        } else{
            if(s[row + 1][col] - '0' < s[row][col + 1] - '0'){
                ind = col;
                row += 1;
            } else {
                col += 1;
            }
        }
    }

    int count = 0;
    for(int i = ind - 1; i >= 0; i--){
        if(s[0][i + 1] == s[1][i])
            count += 1;
        else 
            break; 
    }

    cout << x << "\n";
    cout << count + 1 << "\n";

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