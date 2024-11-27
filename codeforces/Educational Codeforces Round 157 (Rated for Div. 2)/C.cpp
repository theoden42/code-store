

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
    vector<string> s(n);
    for(int i = 0; i < n; i++){
    	cin >> s[i];
    }
    vector<vector<int>> mp(6, vector<int>(46, 0));
    for(int i = 0; i < n; i++){
    	int sum = 0;
    	for(auto c: s[i]){
    		sum += (c - '0');
    	}
    	mp[s[i].size()][sum] += 1;
    }

    int count = 0;
    for(int i = 1; i <= 5; i++){
    	for(int j = 0; j <= 45; j++){
    		int t = mp[i][j];
    		count += (t * t);
    	}
    }

    for(int i = 0; i < n; i++){
    	int len = s[i].size();
    	vector<int> pref(len + 1);
    	for(int j = 1; j <= len; j++){
    		pref[j] = pref[j - 1];
    		pref[j] += s[i][j - 1] - '0';	
    	}
    	for(int l = len - 1; l >= 1; l--){
    		int total = l + len;
    		if(total & 1)
    			continue;
    		// l length string required;
    		int reqsum1 = pref[total / 2] - pref[0];
    		int reqsum2 = pref[len] - pref[len - total / 2];
    		int avlsum1 = pref[len] -  reqsum1;
    		int avlsum2 = pref[len] - reqsum2;
    		reqsum1 -= avlsum1;
    		reqsum2 -= avlsum2;

    		if(reqsum1 >= 0){
    			count += mp[l][reqsum1];
    		} 
    		if(reqsum2 >= 0){
    			count += mp[l][reqsum2];
    		}
    	}
    }
    cout << count << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}