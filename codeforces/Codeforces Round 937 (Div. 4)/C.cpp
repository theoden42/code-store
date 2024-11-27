

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
    string s;
    cin >> s;
    int hr = stoi(s.substr(0, 2));
    int mn = stoi(s.substr(3));

    int flag = 0;
    if(hr == 0){
    	hr = 12;
    } else if(hr == 12){
    	flag = 1;
   	} else if(hr >= 12){
    	flag = 1;
    	hr -= 12;
    }

    string ans = "";
    if(hr < 10)
    	ans += "0";
    ans += to_string(hr);
    ans += ':';
    if(mn < 10)
    	ans += "0";
    ans += to_string(mn);
    ans += " ";

    if(flag){
    	ans += "PM";
    } else {
    	ans += "AM";
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