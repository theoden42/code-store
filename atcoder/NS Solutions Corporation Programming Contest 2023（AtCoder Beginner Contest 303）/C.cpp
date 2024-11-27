

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
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    map<pair<int,int>, int> item;
    for(int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	item[{x, y}] = 1;
    }

    map<char, pair<int,int>> mp;
    mp['U'] = {0, 1};
    mp['R'] = {1, 0};
    mp['L'] = {-1, 0};
    mp['D'] = {0, -1}; 

    int cx = 0;
    int cy = 0;


    for(int i = 0; i < n; i++){
    	auto& move = mp[s[i]];
    	cx += move.first;
    	cy += move.second;
    	h -= 1;

        if(h < 0){
            cout << "No\n";
            return;
        }

    	if(item[{cx, cy}] == 1 && h < k){
    		h = max(h, k);
    		item[{cx, cy}] = 0;
    	}
        // debug(cx, cy, h);
    }

    cout << "Yes\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}