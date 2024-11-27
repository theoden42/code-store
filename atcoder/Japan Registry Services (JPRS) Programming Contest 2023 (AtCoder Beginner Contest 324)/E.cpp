

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
    string t;
    cin >> t;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
    	cin >> s[i];
    }

    vector<int> mxfront(n), mxback(n);

    auto calcback = [&](string& s){
    	vector<vector<int>> pos(26);
    	for(int i = 0; i < s.size(); i++){
    		pos[s[i] - 'a'].push_back(i);
    	}
    	int mn = t.size();
    	int ind = s.size();
    	for(int i = t.size() - 1; i >= 0; i--){
    		int ch = t[i] - 'a';
    		if(pos[ch].empty() || pos[ch][0] >= ind){
    			return mn;
    		}
    		auto it = lower_bound(all(pos[ch]), ind);
    		--it;
    		ind = *it;
    		mn = min(mn, i);
    	}
    	return mn;
    };

    auto calcfront = [&](string& s){
    	vector<vector<int>> pos(26);
    	for(int i = 0; i < s.size(); i++){
    		pos[s[i] - 'a'].push_back(i);
    	}
    	int mn = -1;
    	int ind = -1;
    	for(int i = 0; i < t.size(); i++){
    		int ch = t[i] - 'a';
    		if(pos[ch].empty() || pos[ch].back() <= ind){
    			return mn;
    		}
    		auto it = upper_bound(all(pos[ch]), ind);
    		ind = *it;
    		mn = max(mn, i);
    	}
    	return mn;
    };

    vector<int> f(n), b(n);
    for(int i = 0; i < n; i++){
    	f[i] = calcfront(s[i]);
    	b[i] = calcback(s[i]);
    }


    int ans = 0;
    sort(all(f));
    sort(all(b));

    int ind = 0;
    for(int i = 0; i < n; i++){
    	int val = f[i];
    	while(ind < n && b[ind] <= val + 1){
    		ind += 1;
    	}
    	ans += ind;
    }

    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}