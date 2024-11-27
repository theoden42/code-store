

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
    vector<int> v(n);
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    }
    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++){
    	mp[v[i]].push_back(i);
    }

    vector<int> ans(n);
    int flag = 0;
    for(auto it: mp){
    	if(it.second.size() < 2){
    		ans[it.second[0]] = 1;
    	} else {
    		flag += 1;
    		if(flag == 1){
    			ans[it.second[0]] = 1;
    			for(int i = 1; i < it.second.size(); i++){
    				ans[it.second[i]] = 2;
    			}
    		} else if(flag == 2){
    			ans[it.second[0]] = 1;
    			for(int i = 1; i < it.second.size(); i++){
    				ans[it.second[i]] = 3;
    			}
    		} else {
    			for(int index: it.second){
    				ans[index] = 1;
    			}
    		}
    	}
    }
    if(flag < 2){
    	cout << "-1\n";
    	return;
    }
    for(int i = 0; i < ans.size(); i++){
    	cout << ans[i] << " ";
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