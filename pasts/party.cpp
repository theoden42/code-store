
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> uh(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> uh[i];
    }
    vector<pair<int,int>> frnds(m);
    map<int,int> mp;
    for(int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	x--;
    	y--;
    	frnds[i] = {x, y};
    	mp[x]++;
    	mp[y]++;
    }	
    if(m % 2 == 0){
    	cout << 0 << "\n";
    	return;
    }
    // for(auto& x: mp){
    // 	cout << x.first << " " << x.second << "\n";
    // 	cout << uh[x.first] << " ";
    // 	cout << "\n";
    // }
    int mx = 1e9 + 5;
    for(int i = 0; i < m; i++){
    	if(mp[frnds[i].first] % 2 == 0 && mp[frnds[i].second] % 2 == 0){
    		int val = uh[frnds[i].first] + uh[frnds[i].second];
    		mx = min(mx, val);
    	}
    	else if(mp[frnds[i].first] % 2 == 1 && mp[frnds[i].second] % 2 == 1){	
    			int val = min(uh[frnds[i].first], uh[frnds[i].second]);
    			mx = min(mx, val);

    	}
    	else{
    		if(mp[frnds[i].first] % 2 == 1){
    			int val = uh[frnds[i].first];
    			mx = min(mx, val);
    		}
    		else{
    			int val = uh[frnds[i].second];
    			mx = min(mx, val);
    		}
    	}
    }
    cout << mx << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}