

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
    string s, t;
    cin >> s >> t;
    map<char,set<int>> mp;
    for(int i = 0; i < s.size(); i++){
    	mp[s[i]].insert(i);
    }
    int lst = -1;
    for(int i = 0; i < t.size(); i++){
    	auto it1 = mp[t[i]].upper_bound(lst);
    	auto it2 = mp['?'].upper_bound(lst);
    	if(it1 == mp[t[i]].end() && it2 == mp['?'].end()){
    		cout << "NO\n";
    		return;
    	} else if(it1 == mp[t[i]].end()) {
    		lst = *it2;
    		s[lst] = t[i];
    	} else if(it2 == mp['?'].end()){
    		lst = *it1;
    	} else {
    		int ind1 = *it1, ind2 = *it2;
    		if(ind1 < ind2){
    			lst = ind1;
    		} else {
    			lst = ind2;
    			s[ind2] = t[i];
    		}
    	}
    }
    for(int i = 0; i < s.size(); i++){
    	if(s[i] == '?')
    		s[i] = 'a';
    }
    cout << "YES\n";
    cout << s << "\n";
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