
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
    int n, x;
    cin >> n >> x;
    vector<int> ele(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    for(int i = 0; i < n; i++){
    	int t = x - ele[i];
    	if(mp[t] != 0){
    		cout << mp[t] << " " << i + 1 << "\n";
    		return;
    	}
    	mp[ele[i]] = i + 1;
    }
    cout << "IMPOSSIBLE\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}