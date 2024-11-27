

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
	    string s;
	    cin >> s;
	    int n = s.size();
	    int c = 0;
	    for(int i = 0; i < s.size(); i++){
	    	if(s[i] != s[0])
	    		c += 1;
	    }
	    int flag = 1;
	    for(int i = 0; i < n; i++){
	    	if(s[i] != s[n - 1 - i]){
	    		flag = 0;
	    	}
	    }
	    if(!flag){
	    	cout << "YES\n";
	    	cout << 1 << "\n";
	    	cout << s << "\n";
	    	return;
	    }
	    if(c <= 1){
	    	cout << "NO\n";
	    	return;	
	    }
	   	string x = "";
	    vector<string> st;
	    for(int i = 0; i < n; i++){
	    	x += s[i];
	    	if(s[i] != s[0]){
	    		break;
	    	} 
	    }
	    int curr = 0;
	    while(curr + x.size() - 1 < n){
	    	string temp = s.substr(curr, x.size());
	    	if(temp == x){
	    		st.push_back(temp);
	    		curr += x.size();
	    	} else {
	    		break;
	    	}
	    }
	    // debug(curr, n, x, n - x.size());
	    if(curr <= n - x.size()){
	    	cout << "YES\n";
	    	st.push_back(s.substr(curr, n - curr));
		    cout << st.size() << "\n";
		    for(int i = 0; i < st.size(); i++){
		    	cout << st[i] << " \n"[i == st.size() - 1];
		    }
	    } else if(curr == n - 1){
	    	cout << "NO\n";
	    	return;
	    } else{
	    	cout << "YES\n";
	    	int sz = st.size();
	    	for(int i = 0; i < x.size() - 2; i++){
	    		st[sz - 2] += s[0];
	    	}
	    	st.back() = st.back().substr(x.size() - 2);
	    	for(int i = 0; i < x.size() - 1; i++){
	    		st.back() += s[0];
	    	}
	    	cout << st.size() << "\n";
	    	for(int i = 0; i < st.size(); i++){
	    		cout << st[i] << " \n"[i == st.size() - 1];
	    	}
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