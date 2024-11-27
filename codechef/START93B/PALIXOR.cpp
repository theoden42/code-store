

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

int check(int n){
	string s = to_string(n);
	int sz = s.size();

	for(int i = 0; i < sz / 2; i++){
		if(s[i] != s[sz - 1 - i])return false;
	}

	return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> mp;
    
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	mp[a[i]]++;
    }


    int ans = 0;

    for(int i = 0; i <= (int)(1 << 15); i++){
    	if(check(i)){
    		int count1 = 0;
    		int count2 = 0;
    		for(int j = 0; j < n; j++){
    			int desired = (i ^ a[j]);

    			if(desired == a[j]){
    				count1 += mp[a[j]] - 1;
    				count2 += 1;
    			}
    			else if(mp.find(desired) != mp.end()){
    				count1 += mp[desired];
    			}
    		}
    		ans += (count1 / 2) + count2;
    	}
    }

    cout << ans << "\n";

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