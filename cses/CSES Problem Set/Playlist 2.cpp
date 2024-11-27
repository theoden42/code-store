
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
    vector<int> v(n);
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    }
    int mx = 0;
    map<int,int> mp;
    int j = 0;
    for(int i = 0; i < n; i++){
    	while(j < n && mp[v[j]] != 1){
    		mp[v[j]] = 1;
    		j++;
    	}
    	mx = max(mx, j - i);
        debug(i, j);

    	while(v[i] != v[j]){
    		mp[v[i]] = 0;
    		i++;
    	}
    	mp[v[i]] = 0;
    }

    cout << mx << "\n";
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