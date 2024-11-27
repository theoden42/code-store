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
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> black;

    for(int i = 0; i < n; i++){
        string st;
        cin >> st;
        for(int j = 0; j < m; j++){
            if(st[j] == 'B'){
                black.push_back({i, j});
            }
        }
    }

    int mndiff = INF;
    pair<int,int> mndiffp;
    int mxdiff = -INF;
    pair<int,int> mxdiffp;

    int mnadd = INF;
    pair<int,int> mnaddp;
    int mxadd = -INF;
    pair<int,int> mxaddp;


    for(auto cell : black){
        int val1 = cell.first + cell.second;
        int val2 = cell.first - cell.second;

        if(val1 >= mxadd){
            mxadd = val1;
            mxaddp = cell;
        }
        if(val1 <= mnadd){
            mnadd = val1;
            mnaddp = cell;
        }
        if(val2 >= mxdiff){
            mxdiff = val2;
            mxdiffp = cell;
        }
        if(val2 <= mndiff){
            mndiff = val2;
            mndiffp = cell;
        }
    }

    debug(mndiffp, mxdiffp, mnaddp, mxaddp);

    int mnans = INF;
    int ansrow = 0;
    int anscol = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int dis1 = abs(mxaddp.first - i) + abs(mxaddp.second - j);
            int dis2 = abs(mnaddp.first - i) + abs(mnaddp.second - j);
            int dis3 = abs(mxdiffp.first - i) + abs(mxdiffp.second - j);
            int dis4 = abs(mndiffp.first - i) + abs(mndiffp.second - j);
            int dist = max({dis1, dis2, dis3, dis4});
            if(dist < mnans){
                mnans = dist;
                ansrow = i;
                anscol = j;
            }
        }
    }

    cout << ansrow + 1 << " " << anscol + 1 << "\n";


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