

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


vector<vector<int>> adj;
vector<int> depths;
vector<int> maxsub;

int dfs(int source, int parent, int maxheight, int curr, int& count){
	int mx = 0;
	if(curr > maxheight){
		mx = curr - maxheight + 1;
	}

	for(auto x: adj[source]){
		if(x == parent)continue;
		int val = dfs(x, source, maxheight, curr + 1, count);
		if(val > curr){
			count++;
		}
		else{
			mx = max(mx, val);
		}
	}	

	return mx;

}
/*

 need to reduce the height of all the leaves by atleast mx - curr so the height of the subtree to be rooted must be
	h - 1 = mx - curr => h >= mx - curr + 1 so if i can wait for a child, i will and return the wait I can suffice
 */


int calcdepth(int source, int parent){
	depths[source] = 0;
	int mx = 0;
	for(auto x: adj[source]){
		if(x != parent){
			mx = max(mx, 1 + calcdepth(x, source));
		}
	}
	depths[source] = mx;
	return mx;
}

int calcmax(int source, int parent){
	maxsub[source] = depths[source];
	for(auto x: adj[source]){
		if(x == parent)continue;

		maxsub[source] = max(maxsub[source], calcmax(x, source));
	}
	return maxsub[source];	
}

void solve() {
    int n, k;
   	cin >> n >> k;
   	adj.clear();
   	depths.clear();
   	maxsub.clear();


   	adj.resize(n + 1);
   	depths.resize(n + 1);
   	maxsub.resize(n + 1);

   	for(int i = 2; i <= n; i++){
   		int x;
   		cin >> x;
   		adj[i].push_back(x);
   		adj[x].push_back(i);
   	}


   	int l = 1;
   	int u = n;
   	int ans = n + 1;

   	function<int(int)> check = [&](int value){

   		int count = 0;
   		dfs(1, -1, value, 0, count);


   		if(count > k)return false;
   		else return true;
   	};

   	while(l <= u){
   		int mid = l + (u - l) / 2;
   		if(check(mid)){
   			ans = mid;
   			u = mid - 1;
   		}
   		else{
   			l = mid + 1;
   		}
   	}

   	cout << ans << "\n";
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