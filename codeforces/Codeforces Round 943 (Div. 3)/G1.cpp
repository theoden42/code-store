

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
    int n, l, r, k;
    cin >> n >> l >> r;
    k = l;
    string s;
    cin >> s;
    int lb = 1;
    int ub = n;

    auto check = [&](int mid){
    	if(mid > s.size())
    		return false;
    	auto x = s.substr(0, mid);
    	int l = x.size();
    	string temp = x + "#" + s;
    	int sz = temp.size();
    	vector<int> pi(sz);
    	for(int i = 1; i < sz; i++){
    		int j = pi[i - 1];
    		while(j > 0 && temp[j] != temp[i]){
    			j = pi[j - 1];
    		}
    		if(temp[j] == temp[i])
    			pi[i] = j + 1;
    		else 
    			pi[i] = j;
    	}
    	vector<int> occur;
    	for(int k = l + 1; k < sz; k++){
    		if(pi[k] == l){
    			occur.push_back(k - 2 * l);
    		}
    	}
    	reverse(all(occur));
    	int count = 0;
    	int lst = 0;
    	while(!occur.empty()){
    		while(!occur.empty() && occur.back() < lst){
    			occur.pop_back();
    		}
    		if(!occur.empty()){
    			count += 1;
    			lst = occur.back() + mid;
    		}
    	}
    	return (count >= k);
    };	
    int ans = 0;
    while(lb <= ub){
    	int mid = lb + (ub - lb) / 2;
    	if(check(mid)){
    		ans = mid;
    		lb = mid + 1;
    	} else{
    		ub = mid - 1;
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