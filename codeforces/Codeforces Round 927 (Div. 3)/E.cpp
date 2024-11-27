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
    string s;
    cin >> s;
    vector<int> p(n + 1);
    for(int i = 0; i < n; i++){
        p[i + 1] += p[i];
        p[i + 1] += (s[i] - '0');
    }
    // debug(p);
    string ans = "";
    int cr = 0;
    for(int i = n; i > 0; i--){
        int s = p[i];
        s += cr;
        ans += ('0' + s % 10);
        cr = s / 10;
    }
    if(cr != 0)
        ans += to_string(cr);
    while(ans.size() != 1 && ans.back() == '0')
        ans.pop_back();
    reverse(all(ans));
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