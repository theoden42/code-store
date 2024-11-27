

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
    int flag = 1;
    string s = "";

    auto check = [&](string s){
    	cout << "? " << s << endl;
    	int x;
    	cin >> x;
    	if(x == -1)
    		exit(0);
    	return x;
    };

    if(n == 1){
    	if(check("1")){
    		cout << "! 1" << endl;
    	} else {
    		cout << "! 0" << endl;
    	}
    	return;
    }

    if(check("01")){
    	s = "01";
    } else if(check("10")){
    	s = "10";
    } else {
    	if(check("1")){	
    		for(int i = 0; i < n; i++){
    			s += "1";
    		}
    	} else {
    		for(int i = 0; i < n; i++){
    			s += "0";
    		}
    	}
    	cout << "! " << s << endl;
    	return;
    }

    for(int i = 2; i < n; ++i){
    	if(flag){
    		s += "0";
    		if(check(s))
    			continue;
    		else{
    			s.pop_back();
    			s += "1";
    			if(check(s))
    				continue;
    			else {
    				s.pop_back();
    				flag = 1 - flag;
    				i -= 1;
    				continue;
    			}
    		}
    	} else {
    		s = "1" + s;
    		if(check(s))
    			continue;
    		else{
    			s = s.substr(1);
    			s = "0" + s;
    			if(check(s))
    				continue;
    			else{
    				s = s.substr(1);
    				flag = 1 - flag;
    				i -= 1;
    				continue;
    			}
    		}
    	}
    }

    cout << "! " << s << endl;
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