

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
    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	int x = a[i];
    	if(x & 1)
    		x -= 1;
    	if(x >> 1 & 1)
    		x -= 2;
    	mp[x].push_back(i);
    }

    for(auto [val, v]: mp){
    	vector<int> vals;
    	for(auto ind: v){
    		vals.push_back(a[ind]);
    	}
    	sort(all(vals));
    	int count = 0;
    	for(auto ind: v){
    		a[ind] = vals[count++];
    	}
    }

    for(int i = 0; i < n; i++){
    	cout << a[i] << " \n"[i == n - 1];
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