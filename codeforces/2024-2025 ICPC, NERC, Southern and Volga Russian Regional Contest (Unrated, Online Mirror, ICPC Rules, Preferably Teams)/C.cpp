

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
    map<int,int> mp;
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    for(auto x: a){
    	mp[x] += 1;
    }
 	int count = 0;
 	for(auto [k, v]: mp){
 		if(v >= 2){
 			count += 1;
 		}
 	}   
 	int sm = -1e18;
 	for(auto [k, v]: mp){
 		if(v >= 2){
 			if(sm == -1e18)
 				sm = k;
 		}
 	}
 	if(sm == -1e18){
 		cout << "NO\n";
 		return;
 	}
 	mp[sm] -= 2;
 	debug(sm, mp);
 	int ly = -1e18;
 	for(auto [k , v]: mp){
 		if(v >= 2)
 			ly = k;
 	}
 	if(ly == -1e18){
 		cout << "NO\n";
 		return;
 	}
 	mp[ly] -= 2;
 	debug(ly, mp);
 	int sm2 = -1e18;
 	for(auto [k, v]: mp){
 		if(v >= 2 && sm2 == -1e18){
 			sm2 = k;
 		}
 	}
 	if(sm2 == -1e18){
 		cout << "NO\n";
 		return;
 	}
 	mp[sm2] -= 2;
 	int ly2 = -1e18;
 	for(auto [k, v]: mp){
 		if(v >= 2)
 			ly2 = k;
 	}
 	if(ly2 == -1e18){
 		cout << "NO\n";
 		return;
 	}
 	mp[ly2] -= 2;
 	cout << "YES\n";
 	cout << sm << " " << sm2
 	 << " " << sm << " " << ly
 	 << " " << ly2 << " " << sm2 
 	 << " " << ly2 << " " << ly << "\n";

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