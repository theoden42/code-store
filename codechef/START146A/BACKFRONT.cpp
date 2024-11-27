

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,set<int>> mp;
    for(int i = 0; i < n; i++){
    	mp[s[i]].insert(i);
    }
    int count = 0;
    int frontcn = 0;
    int stop = 0;
    while(!stop) { 
    	string t = "kcab";
    	int lst = n + 1;
    	for(auto c : t){
    		auto it = mp[c].lower_bound(lst);
    		if(mp[c].empty() || it == mp[c].begin()){
    			if(frontcn > 0){
    				frontcn -= 1;
    				lst = -1;
    			} else {
    				stop = 1;
    				break;
    			}
    		} else {
    			--it;
    			lst = *it;
    			mp[c].erase(it);
    		}
    	}
    	if(!stop){
    		count += 3;
    		frontcn += 1;
    	}
    }


    int backcn = 0;
    stop = 0;
    while(!stop){
    	string t = "front";
    	int lst = -1;
    	for(auto c: t){
    		auto it = mp[c].upper_bound(lst);
    		if(mp[c].empty() || it == mp[c].end()){
    			if(backcn > 0){
    				backcn -= 1;
    				lst = n + 1;
    			} else {
    				stop = 1;
    				break;
    			}
    		} else {
    			lst = *it;
    			mp[c].erase(it);
    		}
    	}	
    	if(!stop){
    		count += 4;
    		backcn += 1;
    	}
    }
    while(backcn >= 5){
    	count += 4;
    	backcn -= 4;
    }

    int final = n - count;
    cout << final << "\n";
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