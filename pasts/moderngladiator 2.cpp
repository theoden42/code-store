
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(3, 0);
    map<string,int> mp;
    mp["bronze"] = 0;
    mp["silver"] = 1;	
    mp["gold"] = 2;

    for(int i = 0; i < n; i++){
    	string s;
    	cin >> s;
    	if(mp[s] == 0){
    		ar[0]++;
    	}
    	else{
    		if(mp[s] == 1){
    			if(ar[0] >= 1){
    				ar[0]--;
    				ar[1]++;
    			}
    			else{
    				cout << "NO" << "\n";
    				return;
    			}
    		}
    		else{
    			if(ar[1] >= 1 && ar[0] >= 1){
    				ar[1] -= 1;
    				ar[0] -= 1;
    				ar[2]++;
    			}
    			else if(ar[0] >= 3){
    				ar[0] -= 3;
    				ar[2]++;
    			}
    			else{
    				cout << "NO" << "\n";
    				return;
    			}
    		}
    	}
    }
    cout << "YES" << "\n";
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