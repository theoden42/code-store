

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

map<char,pair<int,int>> mp = {{'U', {0, 1}}, {'D', {0, -1}}, {'L', {-1, 0}}, {'R', {1, 0}}};


void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<pair<int,int>> pref(n + 1, {0, 0});
    vector<pair<int,int>> suff(n + 1, {0, 0});

    for(int i = 1; i <= n; i++){
        auto dd =  mp[s[i - 1]];
        auto dd2 = mp[s[n - i]];
        pref[i] = {pref[i - 1].first + dd.first,
                   pref[i - 1].second + dd.second};
        suff[i] = {suff[i - 1].first + dd2.first, 
                    suff[i - 1].second + dd2.second};
    }

    // debug(pref, suff);

    map<pair<int,int>, vector<int>> ind1, ind2;
    for(int i = 0; i <= n; i++){
        ind1[pref[i]].push_back(i);
    }
    for(int i = n; i >= 0; i--){
        ind2[suff[i]].push_back(n + 1 - i);
    }

    for(int i = 1; i <= q; i++){
        int x, y, l, r;
        cin >> x >> y >> l >> r;

        auto it1 = lower_bound(ind1[{x, y}].begin(), ind1[{x, y}].end(), r);
        if(it1 != ind1[{x, y}].end()){
            // debug(*it1);
            cout << "YES\n";
            continue;
        }
        auto it2 = lower_bound(ind1[{x, y}].begin(), ind1[{x, y}].end(), l);
        if(it2 != ind1[{x, y}].begin()){
            // debug(*it2);
            cout << "YES\n";
            continue;
        }


        int sx = x - pref[l - 1].first + suff[(n - r)].first;
        int sy = y - pref[l - 1].second + suff[n - r].second;
        // debug(pref[l - 1], suff[n - r]);
        // debug(x, y, sx, sy);
        auto it3 = lower_bound(ind2[{sx, sy}].begin(), ind2[{sx, sy}].end(), l);
        auto it4 = upper_bound(ind2[{sx, sy}].begin(), ind2[{sx, sy}].end(), r);
        if(it4 == ind2[{sx, sy}].begin()){
            cout << "NO\n";
            continue;
        }
        --it4;
        if(it3 <= it4){
            cout << "YES\n";
            continue;
        } else {
            cout << "NO\n";
        }
    }
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