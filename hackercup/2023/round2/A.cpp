/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divyanshtripathi <divyanshtripathi@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:42:36 by divyanshtripathi  #+#    #+#             */
/*   Updated: 2023/10/21 22:51:27 by divyanshtripathi ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

vector<vector<int>> dis = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() {
	int r, c;
	cin >> r >> c;
	vector<string> grid(r);
	for(int i = 0; i < r; i++){
		cin >> grid[i];
	}

	vector<vector<int>> vis(r, vector<int>(c, 0));

	function<void(int, int, set<pair<int,int>>&, int&)> dfs = [&](int i, int j, set<pair<int,int>>& st, int& count){
		vis[i][j] = 1;
		count += 1;
		for(auto d: dis){
			int x = i + d[0];
			int y = j + d[1];
			if(x < 0 || x >= r || y < 0 || y >= c)
				continue;
			if(grid[x][y] == '.'){
				st.insert({x, y});		
			}
			if(!vis[x][y] && grid[x][y] == 'W'){
				dfs(x, y, st, count);
			}
		}
	};

	map<pair<int,int>, int> mp;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(grid[i][j] == 'W' && !vis[i][j]){
				int count = 0;
				set<pair<int,int>> st;
				dfs(i, j, st, count);
				if(st.size() == 1){
					mp[*st.begin()] += count;
				}
			}
		}
	}
	int mx = 0;
	for(auto it: mp){
		mx = max(mx, it.second);
	}
	cout << mx << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}