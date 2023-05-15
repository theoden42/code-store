
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
    int m;
    cin >> m;
    vector<vector<int>> a(m);
    for(int i = 0; i < m; i++){
    	int n;
    	cin >> n;
    	for(int j = 0; j < n; j++){
    		int x;
    		cin >> x;
    		a[i].push_back(x);
    	}
    }
    vector<int> ans;
    map<int,int> mp;
    for(int i = m - 1; i >= 0; i--){
    	int flag = 0;

    	for(int j = 0; j < a[i].size(); j++){

    		if(mp[a[i][j]] != 1){
    			ans.push_back(a[i][j]);
    			flag = 1;
    			break;
    		}
    	}

    	if(!flag){
    		cout << "-1\n";
    		return;
    	}
    	for(int j = 0; j < a[i].size(); j++){
    		mp[a[i][j]] = 1;
    	}
    }



    reverse(all(ans));
    for(int i = 0; i < m; ++i){
    	cout << ans[i] << " ";
    }
    cout << "\n";
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