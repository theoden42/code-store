
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
	int n, m;;
	cin >> n >> m;
	vector<string> g(n);
	for(int i = 0; i < n; i++){
		cin >> g[i];
	}	
	vector<vector<int>> crow(n, vector<int>(26, 0)), ccol(m, vector<int>(26, 0));
	vector<int> cdrow(n), cdcol(m);

	multiset<pair<int,int>> row, col;
	set<int> removedrow, removedcol;

	for(int i = 0; i < n; i++){
		set<int> st;
		for(int j = 0; j < m; j++){
			st.insert(g[i][j]);
			crow[i][g[i][j] - 'a']++;
		}
		row.insert({st.size(), i});
		cdrow[i] = st.size();
	}
	for(int j = 0; j < m; j++){
		set<int> st;
		for(int i = 0; i < n; i++){
			st.insert(g[i][j]);
			ccol[j][g[i][j] - 'a']++;
		}
		col.insert({st.size(), j});
		cdcol[j] = st.size();
	}

	while(!row.empty() || !col.empty()){
		debug(row, col);
		if(row.begin() -> first < 0){
			row.erase(row.begin());
			continue;
		}
		if(col.begin() -> first < 0){
			col.erase(col.begin());
			continue;
		}
		auto it = *row.begin();
		auto it2 = *col.begin();

		if(it.first == 1){
			int count = 0;
			for(int j = 0; j < m; j++){
				if(removedcol.find(j) == removedcol.end() && removedrow.find(it.first) == removedrow.end()){
					count++;
				}
			}
			if(count == 1){
				row.erase(row.begin());
				continue;
			}

			int chr = 0;
			for(int i = 0; i < 26; i++){
				if(crow[it.second][i] > 0){
					chr = i;
					break;
				}
			}
			for(int j = 0; j < m; j++){
				if(ccol[j][chr] > 0){
					ccol[j][chr] -= 1;
				}
				if(ccol[j][chr] == 0){
					col.erase({cdcol[j], j});					
					cdcol[j] -= 1;
					if(cdcol[j] != 0)
						col.insert({cdcol[j], j});
				}	
			}
			removedrow.insert(it.second);
			row.erase(row.begin());
			continue;
		} 
		else if(it2.first == 1){

			int count = 0;
			for(int j = 0; j < n; j++){
				if(removedrow.find(j) == removedrow.end() && removedcol.find(it2.second) == removedcol.end()){
					count++;
				}
			}
			if(count == 1){
				col.erase(col.begin());
				continue;
			}

			int chr = 0;
			for(int i = 0; i < 26; i++){
				if(ccol[it2.second][i] > 0){
					chr = i;
					break;
				}
			}
			for(int j = 0; j < n; j++){
				if(crow[j][chr] > 0){
					crow[j][chr] -= 1;
				}
				if(crow[j][chr] == 0){
					row.erase({cdrow[j], j});
					cdrow[j] -= 1;
					if(cdrow[j] != 0)
						row.insert({cdrow[j], j});
				}
			}
			removedcol.insert(it.second);
			col.erase(col.begin());
			continue;
		} 
		else {
			break;
		}
	}

	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(removedrow.find(i) == removedrow.end() && removedcol.find(j) == removedcol.end()){
				count++;
			}
		}
	}
	cout << count << "\n";


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}