

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
	    vector<int> a(n);
	    for(int i = 0; i < n; i++){
	    	cin >> a[i];
	    }

	    int flag = 1;
	    for(int i = 1; i < n; i++){
	    	if(a[i] < a[i - 1])
	    		flag = 0;
	    }

	    if(flag){
	    	cout << "YES\n";
	    	return;
	    }

	    vector<int> temp;
	    for(int i = 0; i < n; i++){
	    	vector<int> vals;
	    	string str = to_string(a[i]);
	    	int t = 0;
	    	for(auto c: str){
				temp.push_back(c - '0');
	    	}
	    	if(i == n - 1 || a[i + 1] >= temp.back()){
	    		int f = 1;
	    		for(int j = 0; j < temp.size() - 1; j++){
	    			if(temp[j] > temp[j + 1]){
	    				f = 0;
	    				break;
	    			}
	    		}
	    		for(int j = i + 1; j < n - 1; j++){
	    			if(a[j] > a[j + 1]){
	    				f = 0;
	    				break;
	    			}
	    		}

	    		if(f){
	    			cout << "YES\n";
	    			return;
	    		}
	    	}
	    }

	    cout << "NO\n";
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