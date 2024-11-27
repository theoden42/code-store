

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), x(n + 1);
    for(int i = 1; i <= n; i++)
    	cin >> x[i];
    for(int i = 1; i <= n; i++)
    	cin >> a[i];

    vector<int> b(n + 1);
    vector<int> vis(n + 1);
    vector<int> curr(n + 1);
    vector<int> cycle(n + 1, -1);
    vector<int> temp;
    function<int(int, vector<int>&)> dfs = [&](int pos, vector<int>& st){
        debug(pos);
    	vis[pos] = 1;
    	curr[pos] = 1;
    	st.push_back(pos);
        int ans = 0;
    	if(curr[x[pos]]){
            temp.clear();
    		for(int i = st.size() - 1; i >= 0; i--){
    			temp.push_back(st[i]);
    			if(st[i] == x[pos])
    				break;
    		}
    		int sz = temp.size();
    		for(int i = 0; i < sz; i++){
    			cycle[temp[i]] = temp[(i - k % sz + sz) % sz];
    		}
            ans = 0;
    	} else if(!vis[x[pos]]){
    		ans = dfs(x[pos], st);
    	}
        if(cycle[pos] == -1 && ans + 1 <= k){
            debug(pos, ans + 1, temp);
            int sz = temp.size();
            int t = (k - ans - 1) % sz;
            debug(t);
            cycle[pos] = temp[(sz - t) % sz];
        }
    	curr[pos] = 0;
    	st.pop_back();
        return ans + 1;
    };
    for(int i = 1; i <= n; i++){
    	vector<int> temp;
    	if(!vis[i])
    		dfs(i, temp);
    }
    for(int i = 1; i <= n; i++){
    	if(cycle[i] == -1){
            vector<int> vals;
            int j = i;
            while(cycle[j] == -1){
                vals.push_back(j);
                j = x[j];
            }
            for(int i = 0; i < vals.size(); i++){
                if(cycle[vals[i]] == -1){
                    cycle[vals[i]] = vals[i + k];
                }
            }
    	} 
    }
    debug(cycle);
    for(int i = 1; i <= n; i++){
    	b[i] = a[cycle[i]];
    }
    for(int i = 1; i <= n; i++)
    	cout << b[i] << " \n"[i == n];
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