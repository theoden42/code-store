

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
    string s;
    cin >> s;

    set<char> ans;
    for(int x = 1; x <= n; x++){
    	int seta = 0;
    	int setb = 0;
    	int ca = 0;
    	int cb = 0;
    	for(int i = 0; i < n; i++){
    		if(s[i] == 'A'){
    			ca += 1;
    		} else {
    			cb += 1;
    		}	
    		if(ca == x){
    			seta += 1;
    			ca = 0;
    			cb = 0;
    		} else if(cb == x){
    			setb += 1;
    			cb = 0;
    			ca = 0;
    		}
    	}
    	if(ca != 0 || cb != 0)
    		continue;
    	// debug(x, seta, setb);
    	if(seta == setb){
    		continue;
    	} else if(seta < setb && s.back() == 'B'){
    		ans.insert('B');
    	} else if(s.back() == 'A'){
    		ans.insert('A');
    	}
    }
    if(ans.size() > 1){
    	cout << "?\n";
    } else {
    	cout << *ans.begin() << "\n";
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