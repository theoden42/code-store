

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
    string t;
    cin >> t;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
    	cin >> s[i];
    }


    auto equal = [&](string& s, string& t)->bool{
    	if(s.size() == t.size() + 1){
    		int count = 0;
    		int ind = 0;
    		for(int i = 0; i < t.size(); i++, ind += 1){
    			if(s[ind] == t[i])
    				continue;
    			else {
    				if(count == 0){
    					count += 1;
    					i--;
    					continue;
    				} else {
    					return 0;
    				}
    			}
    		}
    		return 1;
    	} else if(s.size() == t.size() - 1){
    		int count = 0;
    		int ind = 0;
    		for(int i = 0; i < s.size(); i++, ind += 1){
    			if(s[i] == t[ind]){
    				continue;
    			} else {
    				if(count == 0){
    					count += 1;
    					i--;
    					continue;
    				} else {
    					return false;
    				}
    			}
    		}
    		return true;
    	} else if(s.size() == t.size()){
    		int count = 0;
    		for(int i = 0; i < s.size(); i++){
    			if(s[i] != t[i])
    				count += 1;
    		}
    		if(count > 1){
    			return 0;
    		} else {
    			return 1;
    		}
    	} else {
    		return 0;
    	}
    };

    vector<int> ans;
    for(int i = 0; i < n; i++){
    	if(equal(s[i], t)){
    		ans.push_back(i + 1);
    	}
    }
    cout << ans.size() << "\n";
    for(auto i: ans){
    	cout << i << " ";
    }
    cout << "\n";
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