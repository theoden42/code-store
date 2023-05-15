
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ele(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> ele[i][j];
    	}
    }
    vector<pair<int,int>> paths;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		paths.push_back({ele[i][j], i});
    	}
    }
    sort(all(paths));

    for(int i = 0; i < m; i++){
    	for(int j = 0; j < m; j++){
    		if(ele[paths[i].second][j] == paths[i].first){
    			ele[paths[i].second][j] = -1;
    		}
    	}
    }
    debug(ele);
    debug(paths);
	vector<vector<pair<int,int>>> rt(m);
	int k = 0;
	for(int i = 0; i < m; i++){
		rt[i].push_back(paths[k]);
		for(int a = 0; a < n; a++){
			if(a != paths[k].second){
				for(int b = 0; b < m; b++){
					if(ele[a][b] != -1){
						rt[i].push_back({ele[a][b], a});
						ele[a][b] = -1;
						break;
					}
				}
			}
		}
		k++;
	}
	debug(rt);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			rt[i][j] = {rt[i][j].second, rt[i][j].first};
		}	
	}

	for(int i = 0; i < m; i++){
		sort(all(rt[i]));
	}
	debug(rt);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << rt[j][i].second << " ";
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