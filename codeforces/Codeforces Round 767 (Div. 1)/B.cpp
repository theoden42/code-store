

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
    vector<string> v(n);
    map<string,int> mp1, mp2, mp3;
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    }
    for(int i = 0; i < n; i++){
    	if(v[i][0] == v[i].back()){
    		cout << "YES\n";
    		return;
    	}
    }

    for(int i = n - 1; i >= 0; i--){
    	if(v[i].size() == 3) { 
    		string t = v[i];
    		reverse(all(t));
    		if(mp3.find(t) != mp3.end() || mp1.find(t.substr(1, 2)) != mp1.end()){
    			cout << "YES\n";
    			return;
    		}
    		mp3[v[i]] += 1;
    		mp2[v[i].substr(1, 2)] += 1;
    	} else {
    		string t = v[i];
    		reverse(all(t));
    		if(mp1.find(t) != mp1.end() || mp2.find(t) != mp2.end()){
    			cout << "YES\n";
    			return;
    		}
    		mp1[v[i]] += 1;
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