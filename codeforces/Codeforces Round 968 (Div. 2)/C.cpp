

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
    string s;
    cin >> s;
    vector<int> f(26);
    vector<pair<int,int>> ch(26);
    for(int i = 0; i < n; i++){
    	f[s[i] - 'a'] += 1;
    }
    for(int i = 0; i < 26; i++){
    	ch[i] = {f[i], i};
    }
    sort(all(ch));
    reverse(all(ch));
    string ans = "";
    vector<vector<char>> vst;
    for(int i = 0; i < ch[0].first; i++){
    	vst.push_back({(char)('a' + ch[0].second)});
    }
    int ind = 0;
    for(int i = 1; i < 26; i++){
        for(int j = 0; j < ch[i].first; j++){
            vst[ind].push_back(char('a' + ch[i].second));
            ind += 1;
            ind %= int(vst.size());
        }
    }

    // for(auto &v : vst){
    // 	sort(all(v));
    // }
    for(auto &v : vst){
    	// debug(v);
    	for(auto &x : v){
    		cout << x;
    	}
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