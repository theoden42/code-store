
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

map<pair<int,int>, int> parent;
map<pair<int,int>, int> size;

int getparent()

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    map<int,int> mp;

    for(int i = 0; i < n; i++){
    	int a, b;
    	cin >> a >> b;
    	vp[i] = {a, b};
    	mp[a]++;
    	mp[b]++;
    }

    for(auto& x: mp){
    	if(x.second > 2){
    		cout << "NO\n";
    		return;
    	}
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