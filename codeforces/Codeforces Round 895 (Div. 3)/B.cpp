

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
    vector<int> mp(300, -1);
    for(int i = 0; i < n; i++){
    	int d, s;
    	cin >> d >> s;
    	if(mp[d] == -1)
    		mp[d] = s;
    	else 
    		mp[d] = min(mp[d], s);
    }


    int low = 1; 
    int high = 1000;
    int ans = 1;

    auto check = [&](int k){
    	int flag = 1;
    	for(int j = 1; j <= k; j++){
    		if(mp[j] == -1)
    			continue;
    		int time = 2 * (k - j);
    		if(time < mp[j])
    			continue;
    		else{
    			flag = 0;
    			break;
    		}
    	}
    	return flag;
    };


    while(low <= high){
    	int mid = (low + high) / 2;
    	if(check(mid)){
    		ans = mid;
    		low = mid + 1;
    	} else {
    		high = mid - 1;
    	}
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