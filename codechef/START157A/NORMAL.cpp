

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
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    	cin >> v[i];
    int cnt = 0;
    for(int i = 0; i < n; i++){
    	int j = i;
    	int sz = 0;
    	while(j < n && v[j] == v[i]){
    		sz += 1;
    		j += 1;
    	}
    	cnt += (sz * (sz + 1)) / 2;
    	i = j - 1;
    }
    vector<int> ones(n + 1), three(n + 1), pref(n + 1);
    for(int i = 1; i <= n; i++){
    	ones[i] = ones[i - 1];
    	three[i] = three[i - 1];
    	if(v[i - 1] == 1){
    		ones[i] += 1;
    	} else if(v[i - 1] == 3){
    		three[i] += 1;
    	}
    	pref[i] = ones[i] - three[i];
    }
    vector<int> val;
    unordered_map<int,int> mp;
    for(int i = 0; i <= n; i++){
        if(i > 0 && v[i - 1] == 2){
            for(auto x: val){
                mp[x] += 1;
            }
            val.clear();
        }
    	int x = pref[i];
    	cnt += mp[x];
        val.push_back(x);
    }
    for(int i = 0; i < n; i++) if(v[i] == 2){
        int j = i;
        int sz = 0; 
        while(j < n && v[j] == v[i]){
            sz += 1;
            j += 1;
        }   
        cnt -= (sz * (sz + 1)) / 2;
        i = j - 1;
    }
    cout << cnt << '\n';
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