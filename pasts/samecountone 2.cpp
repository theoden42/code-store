
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
    vector<vector<int>> val(n, vector<int>(m, 0));
    int count = 0;


    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		cin >> val[i][j];
    		if(val[i][j] == 1){
    			count++;
    		}
    	}
    }

    if(count % n != 0){
    	cout << "-1\n";
    	return;
    }


    map<int, queue<int>> mp;
    vector<int> excess(n, 0);

    for(int i = 0; i < n; i++){
    	int c = 0;
    	for(int j = 0; j < m; j++){
    		if(val[i][j] == 1){
    			if(mp[j].empty()){
    				mp[j] = queue<int>();
    			}
    			debug(i, j);
    			mp[j].push(i);
    			c++;
    		}
    	}
    	excess[i] = c;
    }

    int v = count / n;

    vector<vector<int>> ans;


    for(int i = 0; i < n; i++){

    	if(excess[i] >= v)continue;
    	int ex = v - excess[i];

    	for(int j = 0; j < m && ex > 0; j++){
    		if(val[i][j] == 1)continue;

    		while(!mp[j].empty() && excess[mp[j].front()] <= v){
    			debug(i, j, mp[j].front(), excess[mp[j].front()]);
    			mp[j].pop();
    		}

    		if(mp[j].empty())continue;
    		debug(i, j, mp[j].front(), excess[mp[j].front()]);

    		int q = mp[j].front();
    		mp[j].pop();
    		excess[q]--;
    		ex--;
    		ans.push_back({q + 1, i + 1, j + 1});
    	}
    	assert(ex == 0);
    }


    cout << ans.size() << "\n";
    for(auto& x: ans){
    	for(auto& y: x){
    		cout << y << " ";
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