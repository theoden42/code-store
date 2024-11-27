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
	    vector<string> s(3);
	    for(int i = 0; i < 3; i++){
	    	cin >> s[i];
	    }

	    vector<vector<int>> change(3);
	    for(int i = 0; i < 3; i++){
	    	for(int j = 1; j < 2 * n; j++){
	    		if(s[i][j] != s[i][j - 1]){
	    			change[i].push_back(j);
	    		}
	    	}
	    }

	    // debug(change);

	    string temp = "";
	    auto check = [&](string& a, string& b, vector<int>& c1, vector<int>& c2){
	    	temp.clear();
	    	int i = 0; 
	    	int j = 0;
	    	while(i < a.size() && j < b.size()){
	    		if(a[i] == b[j]){
	    			temp += a[i];
	    			i += 1;
	    			j += 1;
	    		} else {
	    			auto val = upper_bound(all(c1), i) - c1.begin() - i;
	    			auto val2 = upper_bound(all(c2), j) - c2.begin() - j;
	    			if(val < val2){
	    				temp += a[i];
	    				i += 1;
	    			} else {
	    				temp += a[j];
	    				j += 1;
	    			}
	    		}
	    	}
	    	while(i < a.size()){
	    		temp += a[i];
	    		i += 1;
	    	}
	    	while(j < b.size()){
	    		temp += b[j];
	    		j += 1;
	    	}
	    	if(temp.size() <= 3 * n){
	    		return true;
	    	} else {
	    		return false;
	    	}
	    };

	    for(int i = 0; i < 3; i++){
	    	for(int j = 0; j < 3; j++){
	    		if(i == j)
	    			continue;
	    		if(check(s[i], s[j], change[i], change[j])){
	    			// debug(i, j);
	    			cout << temp << "\n";
	    			return;
	    		}
	    	}
	    }
	    cout << temp << "\n";
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