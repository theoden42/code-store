

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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    vector<int> comp(n);
    int val = 0;

    map<int,int> coordinate;
    for(int i = 0; i < n; i++){
    	if(coordinate.find(a[i]) == coordinate.end()){
    		coordinate[a[i]] = val++;
    	}
    	comp[i] = coordinate[a[i]];
    }

    debug(comp);

    vector<vector<int>> query(q);
    for(int i = 0; i < q; i++){
    	int x, y;
    	cin >> x >> y;
    	x--;
    	y--;
    	query[i] = {x, y, i};
    }

   	const int len = ceil(sqrt(n)) + 1;

    sort(all(query), [&](vector<int>& a, vector<int> & b){
    	return make_pair(a[0] / len, a[1]) < make_pair(b[0] / len, b[1]);
    });	

    vector<int> ans(q);
    int cur_l = 0;
    int cur_r = -1;

    int count = 0;
    vector<int> mp(val);

   	for(auto x: query){
   		int l = x[0];
   		int r = x[1];
   		int ind = x[2];

   		while(cur_l < l){
   			int v = comp[cur_l];
   			mp[v] -= 1;
   			if(mp[v] == 0){
   				count -= 1;
   			}
   			cur_l += 1;
   		}
   		while(cur_l > l){
   			cur_l -= 1;
   			int v = comp[cur_l];
   			if(mp[v] == 0)
   				count += 1;
   			mp[v] += 1;
   		}
   		while(cur_r > r){
   			int v = comp[cur_r];
   			mp[v] -= 1;
   			if(mp[v] == 0)
   				count -= 1;
   			cur_r -= 1;
   		}
   		while(cur_r < r){
   			cur_r += 1;
   			int v = comp[cur_r];
   			if(mp[v] == 0)
   				count += 1;
   			mp[v] += 1;	
   		}

   		ans[ind] = count;
   	}

   	for(int i = 0; i < q; i++){
   		cout << ans[i] << "\n";	
   	}

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}