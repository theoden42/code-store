

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

    vector<vector<int>> adj(26);	
    int q;
    cin >> q;

   	vector<vector<int>> ch(26);
    for(int i = 0; i < 26; i++){
    	ch[i].push_back(i);
    }

    for(int i = 1; i <= q; i++){
    	char c, d;
    	cin >> c >> d;
    	if(c == d)
    		continue;
    	for(auto val: ch[c - 'a'])
    		ch[d - 'a'].push_back(val);

    	ch[c - 'a'].clear();
    }

    map<int,int> mp;
    for(int i = 0; i < 26; i++){
    	for(auto y: ch[i]){
    		mp[y] = i;
    	}
    }

    string ans = "";
    for(auto c: s){
    	ans += (char)('a' + mp[c - 'a']);
    }
    cout << ans << "\n";


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}