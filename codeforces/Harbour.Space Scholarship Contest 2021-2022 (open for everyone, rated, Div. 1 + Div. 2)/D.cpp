

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
    string s, t;
    cin >> s >> t;
    if(t.size() > s.size()){
    	cout << "NO\n";
    	return;
    }

    int n = s.size();

    int ind = s.size() - 1;
    int lst = n;


    for(int i = t.size() - 1; i >= 0; i--){
    	int f = 0;
    	while(ind >= 0){
    		if(s[ind] == t[i] && (lst - ind - 1) % 2 != 1){
    			lst = ind;
    			ind--;
    			f = 1;
    			break;
    		}
    		else{
    			ind--;
    		}
    	}
    	if(!f){
    		cout << "NO\n";
    		return;
    	}
    }
    cout << "YES\n";
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