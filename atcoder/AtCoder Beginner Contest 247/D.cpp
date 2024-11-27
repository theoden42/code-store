

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
   	vector<pair<int,int>> q;
   	int ind = 0;
   	for(int i = 1; i <= n; i++){
   		int t;
   		cin >> t;
   		if(t == 1){
   			int x, c;
   			cin >> x >> c;
   			q.push_back({x, c});
   		} else {
   			int c;
   			cin >> c;
   			int sum = 0;
   			while(c > 0){
   				if(q[ind].second > c){
   					sum += (c * q[ind].first);
   					q[ind].second -= c;
   					c = 0;
   				} else {
   					sum += q[ind].first * q[ind].second; 
   					c -= q[ind].second;
   					ind += 1;
   				}
   			}

   			cout << sum << "\n";
   		}
   	}

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}