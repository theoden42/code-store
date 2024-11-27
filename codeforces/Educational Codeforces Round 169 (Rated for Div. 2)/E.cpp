

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

const int MAX_N = 1e7 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<int> g(MAX_N, -1);

void pre(){
    g[0] = 0;
    g[1] = 1;
    int count = 1;
    for(int i = 2; i < MAX_N; i++){
        if(g[i] != -1)
            continue;
        g[i] = count++;
        for(int j = i; j < MAX_N; j += i){
            if(g[j] == -1){
                g[j] = g[i];
            }
        }
    }
    for(int i = 2; i < MAX_N; i += 2){
        g[i] = 0;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];

    int ans = 0;
    for(auto x: a){
        ans ^= g[x];
    }
    if(ans){
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    pre();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}