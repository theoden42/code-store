
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ele(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ele[i][j];
        }
    }
    map<int, vector<pair<int,int>>> mp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp.find(ele[i][j]) == mp.end()){
                mp[ele[i][j]].push_back({i, j});
            }
            else{
                mp[ele[i][j]].push_back({i, j});
            }
        }
    }
    ll ans = 0;
    for(auto& x: mp){
        debug(x.first, x.second);
        vector<ll> cordx;
        vector<ll> cordy;
        for(auto& y: x.second){
            cordx.push_back(y.first);
            cordy.push_back(y.second);
        }
        sort(all(cordx));
        sort(all(cordy));
        debug(cordx, cordy);
        ll sum = 0;
        int len = cordx.size();
        sum += cordx[len - 1];
        for(int i = len - 2; i >= 0; i--){
            ans += sum;
            ans -= cordx[i] * (len - 1 - i);
            sum += cordx[i];
        }
        sum = 0;
        len = cordy.size();
        sum += cordy[len - 1];
        for(int i = len - 2; i >= 0; i--){
            ans += sum;
            ans -= cordy[i] * (len - 1 - i);
            sum += cordy[i];
        }
    }
    cout << ans << "\n";
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