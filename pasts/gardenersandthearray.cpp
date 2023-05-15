
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
    vector<vector<int>> s(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	int k;
    	cin >> k;
   		for(int j = 0; j < k; j++){
   			int x;
   			cin >> x;
   			s[i].push_back(x);
   			mp[x]++;
   		}
    }
    debug(s);
    debug(mp);

    for(int i = 0; i < n; i++){
    	int flag = 1;
    	for(int j = 0; j < s[i].size(); j++){
    		if(mp[s[i][j]] < 2){
    			flag = 0;
    			break;
    		}
    	}
    	if(flag){
    		cout << "YES\n";
    		return;
    	}
    }
    cout << "NO\n";

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