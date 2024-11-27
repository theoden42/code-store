

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
    vector<vector<int>> seq;
    vector<int> r(n);
    for(int i = 0; i < n; i++){
    	cin >> r[i];
    }
    function<void(int, vector<int>& curr)> dfs
    = [&](int pos, vector<int>& curr){
    	if(pos == n){
    		int sum = 0;
    		for(auto& x: curr) 
    			sum += x;
    		if(sum % k == 0)
    			seq.push_back(curr);
    		return;
    	} 
    	for(int l = 1; l <= r[pos]; l++){
    		curr.push_back(l);
    		dfs(pos + 1, curr);
    		curr.pop_back();
    	}
    }; 
    vector<int> temp;
    dfs(0, temp);
    sort(all(seq));
    for(int i = 0; i < seq.size(); i++){
    	for(auto v: seq[i]){
    		cout << v << " ";
    	}
    	cout << "\n";
    }
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