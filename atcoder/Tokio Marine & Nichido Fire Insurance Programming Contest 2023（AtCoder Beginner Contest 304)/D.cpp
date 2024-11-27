

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

void solve() {
    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;
    vector<int> xcord(n), ycord(n);
    for(int i = 0; i < n; i++){
    	cin >> xcord[i] >> ycord[i];	
    }

    int an;
    cin >> an;
    vector<int> a(an);
    for(int i = 0; i < an; i++){
    	cin >> a[i];
    }
    a.push_back(w);
    int bn;
    cin >> bn;
    vector<int> b(bn);
    for(int i = 0; i < bn; i++){
    	cin >> b[i];
    }
    b.push_back(h);

    map<pair<int,int>, int> mp;

    for(int i = 0; i < n; i++){
    	auto it = upper_bound(all(a), xcord[i]);
    	auto it2 = upper_bound(all(b), ycord[i]);

    	int xnum = it - a.begin();
    	int ynum = it2 - b.begin();
    	mp[{xnum, ynum}]++;
    }

    ll pieces = 1ll * (an + 1) * (bn + 1);
    int mn = INF;
    int mx = 0;
    if(mp.size() < pieces){
    	mn = 0;
    }
    for(auto x: mp){
    	mn = min(mn, x.second);
    	mx = max(mx, x.second);
    }

    cout << mn << " " << mx << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}