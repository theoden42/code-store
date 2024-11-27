

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

    auto check = [&](string s){
    	int count = 0;
    	for(auto x: s){
    		if(x == '(')
    			count += 1;
    		else 
    			count -= 1;

    		if(count < 0)
    			return false;
    	}
    	return (count == 0);
    };

    int count = 0;
    for(int i = 0; i <= n; i++){
    	string temp = "";
    	string temp2 = "";
    	for(int j = 0; j < i; j++){
    		temp += s[j];
    		temp2 += s[j];
    	}
    	temp += '(';
    	temp2 += ')';
    	for(int j = i; j < n; j++){
    		temp += s[j];
    		temp2 += s[j];
    	}

    	if(check(temp))
    		count += 1;
    	if(check(temp2))
    		count += 1;
    }

    cout << count << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //scin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}