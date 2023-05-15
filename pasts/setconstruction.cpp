n
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void filldfs(int n, int source, vector<vector<int>>& g, vector<int>& vis, vector<set<int>>& values, vector<map<int,int>>& mp, vector<int>& level){
	if(vis[source])return;

	vis[source] = 1;

	for(auto& x: g[source]){
		filldfs(n, x, g, vis, values, mp, level);
		for(auto& x: values[x]){
			values[source].insert(x);
		}
	}

	for(int i = 1; i <= n; i++){
		if(mp[level[source]].find(i) == mp[level[source]].end() && values[source].find(i) == values[source].end()){
			mp[level[source]][i] = 1;
			values[source].insert(i);
			break;
		}
	}

}


int dfs(int source, vector<vector<int>>& g, vector<int>& level, vector<int>& vis){
	if(vis[source]){
		return level[source];
	}
	for(auto& x: g[source]){
		level[source] = max(dfs(x, g, level, vis) + 1, level[source]);
	}

	return level[source];
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ele(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < n; j++){
			ele[i][j] = s[j] - '0';
		}
    }
    vector<vector<int>> g(n + 1);

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(ele[i][j] == 1)
    			g[j + 1].push_back(i + 1);
    	}
    }

    debug(g);

    vector<int> level(n + 1, 1);
    vector<int> vis(n + 1, 0);
   	for(int i = 1; i <= n; i++){
   		if(!vis[i]){
   			dfs(i, g, level, vis);
   		}
   	}

   	

   	for(int i = 1; i <= n; i++){
   		vis[i] = 0;
   	}

   	vector<set<int>> values(n + 1);


   	int count = 1;
   	for(int i = 1; i <= n; i++){
   		if(level[i] == 1){
   			vis[i] = 1;
   			values[i].insert(count++);
   		}
   	}



   	vector<map<int,int>> mp(n + 1);

   	for(int i = 1; i <= n; i++){
   		if(!vis[i]){
   			filldfs(n, i, g, vis, values, mp, level);
   		}
   	}
	
	debug(values);


   	// for(int i = 1; i <= n; i++){
   	// 	map<int,int> mp;
   	// 	for(int j = 1; j <= n; j++){
   	// 		if(level[j] == i){
   	// 			for(int k = 1; k <= n; k++){
   	// 				if(mp.find(k) == mp.end()){
   	// 					if(values[j].find(k) == values[j].end()){
   	// 						mp[k] = 1;
   	// 						values[j].insert(k);
   	// 						break;
   	// 					}
   	// 				}

   	// 			}
   	// 		}
   	// 	}
   	// }


   	for(int i = 1; i <= n; i++){
   		cout << values[i].size() << " ";
   		for(auto& x: values[i]){
   			cout << x << " ";
   		}
   		cout << "\n";
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