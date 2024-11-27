

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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> v(n);
    int sum = 0;
    for(int i = 0; i < n - 2; i++){
    	string x = s.substr(i, 3);
    	if(x == "ABC"){
    		v[i] = 1;
    		sum += 1;
    	}
    }
    for(int i = 1; i <= q; i++){
    	int x;
    	char c;
    	cin >> x >> c;
    	x--;
    	s[x] = c;
    	int prev = 0;
    	int nw = 0;
    	for(int j = x; j >= x - 2 && j >= 0; j--){
    		prev += v[j];
    		string x = s.substr(j, 3);
    		if(x == "ABC")
    			v[j] = 1;
    		else 
    			v[j] = 0;
    		nw += v[j];
    	}
    	sum = sum - prev + nw;
    	cout << sum << "\n";
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