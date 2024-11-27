

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
    vector<int> p(n);
    for(int i = 0; i < n; i++){
    	cin >> p[i];
    }

    vector<int> pos(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	pos[i] = p[i] - 1;
    	mp[p[i]] = i;
    }

    vector<int> vis(n);
    map<int,int> cycleno;
    int count = 0;

    for(int i = 0; i < n; i++){
    	if(vis[i])continue;

		int x = i;
		while(!vis[x]){
			vis[x] = 1;
			cycleno[x] = count;
			x = pos[x];
		}
		count++;
    }

    int mn = n;

    for(int i = n; i >= 2; i--){
    	int x = mp[i];
    	int y = mp[i - 1];

    	int ncount = count;
    	if(cycleno[x] == cycleno[y]){
    		ncount++;
    	}
    	else{
    		ncount--;
    	}
    	mn = min(mn, n - ncount);
    }

    cout << mn << "\n";

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