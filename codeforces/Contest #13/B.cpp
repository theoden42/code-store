

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
    string s;
    cin >> s;
  	vector<set<int>> v(k);
    for(int i = 0; i < n; i++){
    	v[i % k].insert(s[i]);
    }
    for(int i = 0; i < k; i++){
    	int count = 0;
    	for(auto x: v[i]){
    		if(x != '?')
    			count += 1;
    	}
    	if(count >= 2){
    		cout << "NO\n";
    		return;
    	}
    }

    for(int i = 0; i < n; i++){
    	if(s[i] == '?'){
    		for(auto x: v[i % k]){
    			if(x != '?'){
    				s[i] = x;
    				break;
    			}
    		}
    	}
    }



    int count1 = 0, count0 = 0, count2 = 0;

    for(int i = 0; i < k; i++){
    	if(s[i] == '1')
    		count1 += 1;
    	else if(s[i] == '0')
    		count0 += 1;
    	else 
    		count2 += 1;
    }

    if(count2 >= abs(count1 - count0)){
    	cout << "YES\n";
    } else {
    	cout << "NO\n";
    }
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