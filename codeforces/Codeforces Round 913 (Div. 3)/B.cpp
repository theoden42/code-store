

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
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int,char>> uppercase;
    vector<pair<int,char>> lowercase;
    for(int i = 0; i < n; i++){
    	if(s[i] != 'b' && s[i] != 'B'){
    		if(s[i] >= 'A' && s[i] <= 'Z'){
    			uppercase.push_back({i, s[i]});
    		} else {
    			lowercase.push_back({i, s[i]});
    		}
    	} else if(s[i] == 'b'){
    		if(!lowercase.empty()){
    			lowercase.pop_back();
    		}
    	} else {
    		if(!uppercase.empty()){
    			uppercase.pop_back();
    		}
    	}
    }
    // debug(lowercase, uppercase);
    string ans = "";
    int i = 0;
    int j = 0;
    while(i < lowercase.size() && j < uppercase.size()){
    	if(lowercase[i].first < uppercase[j].first){
    		ans += lowercase[i].second;
    		i += 1;
    	} else {
    		ans += uppercase[j].second;
    		j += 1;
    	}
    }
    while(i < lowercase.size()){
    	ans += lowercase[i].second;
    	i += 1;
    }
    while(j < uppercase.size()){
    	ans += uppercase[j].second;
    	j += 1;
    }
    cout << ans << "\n";
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