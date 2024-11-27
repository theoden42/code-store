

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
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];

    vector<int> primes;
    for(int i = 2; i <= 305; i++){
    	int cn = 0;
    	for(int j = 1; j * j <= i; j++){
    		if(i % j == 0){
                if(i / j == j){
                    cn += 1;
                } else {
                    cn += 2;
                }
    		}
    	}
    	if(cn > 2)
    		primes.push_back(i);
    }
    debug(primes);

    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	for(auto p: primes){
    		if(p <= a[i])
    			continue;
    		int left = p - a[i];
    		if(mp.find(left) != mp.end() && mp[left] != 0){
    			cout << mp[left] << " " << i + 1 << "\n";
    			return;
    		}
    	}
    	mp[a[i]] = i + 1;
    }
    cout << "-1\n";
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