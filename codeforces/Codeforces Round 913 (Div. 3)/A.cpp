

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
    vector<string> moves;
    for(char c = '1'; c <= '8'; c++){
    	if(c != s[1]){
    		// debug(c, s[0]);
    		string x = "";
    		x += s[0];
    		x += (char)c;
    		moves.push_back(x);
    	}
    }
    for(char c = 'a'; c <= 'h'; c++){
    	if(c != s[0]){
    		string x = "";
    		x += (char)c;
    		x += s[1];
    		moves.push_back(x);
    	}
    }
    for(auto x: moves){
    	cout << x << "\n";
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