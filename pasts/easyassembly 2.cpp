
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
    int n;
    cin >> n;
    map<int,int> mp;

    vector<vector<int>> towers(n);
    vector<int> values;

    for(int i = 0; i < n; ++i){
    	int k;
    	cin >> k;
    	for(int j = 0; j < k; j++){
    		int x;
    		cin >> x;
    		towers[i].push_back(x);
    		values.push_back(x);
    	}
    }

    int count = 0;
    sort(all(values));
    for(int i = 0; i < values.size(); i++){
    	mp[values[i]] = count;
    	count++;
    }

    debug(mp);


    debug(towers);
    int ntowers = n;
    int split = 0;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < towers[i].size(); j++){
    		if(j == towers[i].size() - 1 || mp[towers[i][j]] == mp[towers[i][j + 1]] - 1){
    			continue;
    		} 
    		else{
    			debug(i, j);
    			split += 1;
    			ntowers += 1;
    		}
    	}
    }
    cout << split << " " << ntowers - 1 << "\n";
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