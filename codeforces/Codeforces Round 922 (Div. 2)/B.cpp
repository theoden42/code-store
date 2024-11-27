

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
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];	
    }

    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
    	vp[i] = {max(a[i], b[i]), i};
    }
    sort(all(vp));
    vector<int> ta(n), tb(n);
    for(int i = 0; i < n; i++){
    	auto ind = vp[i].second;
    	ta[i] = a[ind];
    	tb[i] = b[ind];
    }

    for(int i = 0; i < n; i++){
    	cout << ta[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++){
    	cout << tb[i] << " ";
    }
    cout << "\n";
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