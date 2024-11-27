

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
	vector<vector<pair<int,int>>> p(3);
	for(int pol = 0; pol < 3; pol++){
		for(int i = 0; i < 4; i++){
			string s;
			cin >> s;
			for(int j = 0; j < 4; j++){
				if(s[j] == '#'){
					p[pol].push_back({i, j});
				}
			}
		} 
	}

	for(int i = 0; i < 3; i++){
		auto st = p[i][0];
		for(auto& it: p[i]){
			it.first -= st.first;
			it.second -= st.second;
		}
	}

	vector<pair<int,int>> start_pos;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			start_pos.push_back({i, j});
		}
	}

	auto trans = [&](vector<pair<int,int>> v, int s){
		if(s == 0){
			return v;
		} else if(s == 1){
			for(auto& it: v){
				pair<int,int> nw = it;
				nw.first = it.second;
				nw.second = -it.first;
				it = nw;
			}
			return v;
		} else if(s == 2){
			for(auto& it: v){
				it.first *= -1;
				it.second *= -1;
			}
			return v;
		} else {
			for(auto& it: v){
				pair<int,int> nw = it;
				nw.first = -it.second;
				nw.second = it.first;
				it = nw;
			}
			return v;
		}
	};

	auto get_values = [&](vector<vector<pair<int,int>>> p, int s1, int s2, int s3){
		vector<vector<pair<int,int>>> cord(3);
		cord[0] = trans(p[0], s1);
		cord[1] = trans(p[1], s2);
		cord[2] = trans(p[2], s3);

		return cord;
	};


	auto check = [&](int o1, int o2, int o3){
		int flag = 0;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				for(int k = 0; k < 4; k++){
					vector<vector<pair<int,int>>> cord = get_values(p, i, j, k);
					vector<vector<int>> vis(4, vector<int>(4, 0));

					int tempflag = 1;
					for(auto it: cord[0]){
						int x = it.first + start_pos[o1].first;
						int y = it.second + start_pos[o1].second;
						if(x < 0 || x >= 4 || y < 0 || y >= 4 || vis[x][y] == 1){
							tempflag = 0;
							break;
						} else {
							vis[x][y] = 1;
						}
					}
					for(auto it: cord[1]){
						int x = it.first + start_pos[o2].first;
						int y = it.second + start_pos[o2].second;
						if(x < 0 || x >= 4 || y < 0 || y >= 4 || vis[x][y] == 1){
							tempflag = 0;
							break;
						} else {
							vis[x][y] = 1;
						}
					}
					for(auto it: cord[2]){
						int x = it.first + start_pos[o3].first;
						int y = it.second + start_pos[o3].second;
						if(x < 0 || x >= 4 || y < 0 || y >= 4 || vis[x][y] == 1){
							tempflag = 0;
							break;
						} else {
							vis[x][y] = 1;
						}
					}

					for(int i = 0; i < 4; i++){
						for(int j = 0; j < 4; j++){
							if(vis[i][j] != 1){
								tempflag = 0;
							}
						}
					}

					flag |= tempflag;
				}
			}
		}

		return flag;
	};

	for(int o1 = 0; o1 < 16; o1++){
		for(int o2 = 0; o2 < 16; o2++){
			for(int o3 = 0; o3 < 16; o3++){
				if(check(o1, o2, o3)){
					cout << "Yes\n";
					return;
				}
			}
		}
	}


	cout << "No\n";

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