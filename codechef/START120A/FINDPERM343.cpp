

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
    vector<int> a(2 * n);
    for(int i = 0; i < 2 * n; i++){
    	cin >> a[i];
    }

   	vector<int> dis(n + 1);
   	vector<int> vis(n + 1);
   	for(int i = 0; i < 2 * n; i++){
   		if(vis[a[i]])
   			dis[a[i]] += i;
   		else 
   			dis[a[i]] -= i;

   		vis[a[i]] = 1;
   	}
   	debug(dis);
   	vector<pair<int,int>> ord(n + 1);
   	for(int i = 1; i <= n; i++){
   		ord[i] = {dis[i], i};
   	}
   	sort(all(ord));
   	for(int i = n; i >= 1; i--){
   		cout << ord[i].second << " \n"[i == 1];
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