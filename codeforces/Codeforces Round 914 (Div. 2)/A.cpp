

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
    int a, b;
    cin >> a >> b;
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;

    vector<vector<int>> v = {{a, b}, {-a, b}, {a, -b}, {-a, -b}};
    set<pair<int,int>> st1;
    set<pair<int,int>> st2;
    for(auto mv: v){
    	int nx1 = x1 + mv[0];
    	int nx2 = x2 + mv[0];
    	int ny1 = y1 + mv[1];
    	int ny2 = y2 + mv[1];

    	int mx1 = x1 + mv[1];
    	int mx2 = x2 + mv[1];
    	int my1 = y1 + mv[0];
    	int my2 = y2 + mv[0];

    	st1.insert({nx1, ny1});
    	st1.insert({mx1, my1});
    	st2.insert({nx2, ny2});
    	st2.insert({mx2, my2});
    }

    int count = 0;
    for(auto p: st1){
    	if(st2.find(p) != st2.end()){
    		count += 1;
    	}
    }

    cout << count << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}