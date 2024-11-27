
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> ele(n);
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	ele[i] = {x, i};
    }
    sort(all(ele));

    debug(ele);

    vector<pair<int,int>> ans;

    multiset<pair<int,int>> mst;
    for(int i = 0; i < n; i++){
        mst.insert(ele[i]);
    }

    while(!mst.empty()){
        auto x = *(--mst.end());
        auto y = *(----mst.end());
        mst.erase(--mst.end());
        mst.erase(--mst.end());
        if(x.first == 0 || y.first == 0)break;

        else{
            ans.push_back({x.second + 1, y.second + 1});
            mst.insert({x.first - 1, x.second});
            mst.insert({y.first - 1, y.second});
        }
    }
    cout << ans.size() << "\n";
    for(auto& x: ans){
        cout << x.first << " " << x.second << "\n";
    }
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