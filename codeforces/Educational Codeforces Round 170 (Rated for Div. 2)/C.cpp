

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
    vector<int> a(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	mp[a[i]] += 1;
    }
    vector<pair<int,int>> vp;
    for(auto [x, y]: mp){
    	vp.emplace_back(x, y);
    }

    int sz = vp.size();
    int ans = 0;
    int mx = 0;
    vector<int> ind;
    ind.push_back(0);
    for(int i = 0; i < sz; i++){
    	if(i != 0 && vp[i].first != vp[i - 1].first + 1){
    		ind.push_back(i);
    	}
    }

    auto check = [&](int l, int r){
    	int temp_ans = 0;
    	int temp_mx = 0;
    	for(int i = l; i < r && i < l + k; i++){
    		temp_ans += vp[i].second;
    	}
    	temp_mx = temp_ans;
    	for(int i = l; i < r; i++){
    		temp_ans -= vp[i].second;
    		if(i + k < r){
    			temp_ans += vp[i + k].second;
    		}
    		temp_mx = max(temp_mx, temp_ans);
    	}
    	return temp_mx;
    };


    for(int i = 0; i < ind.size(); i++){
    	int end = ((i == ind.size() - 1) ? sz : ind[i + 1]);
    	int val = check(ind[i], end);
    	mx = max(mx, val);
    }
    cout << mx << '\n';
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