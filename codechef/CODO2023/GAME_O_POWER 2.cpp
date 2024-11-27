
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
#define int long long 
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, k, h, a;
    cin >> n >> k >> h >> a;

    vector<int> hlt(n), atk(n);


    for(int i = 0; i < n; i++){
    	cin >> hlt[i];
    }

    for(int i = 0; i < n; i++){
    	cin >> atk[i];
    }


    vector<pair<int,int>> dmg(n);

    for(int i = 0; i < n; i++){
    	int nmoves = (hlt[i] + a - 1) / a;
    	dmg[i] = {(nmoves - 1) * atk[i], i};
    }
    sort(dmg.rbegin(), dmg.rend());

    map<int,int> mp;
    for(int i = 0; i < k; i++){
    	mp[dmg[i].second] = 1;
    }

    int inith = h;

    for(int i = 0; i < n; i++){
    	if(mp[i] == 1)continue;

    	int nmoves = (hlt[i] + a - 1) / a;
    	int dm = (nmoves - 1) * atk[i];

    	if(dm >= inith){
    		cout << "NO\n";
    		return;
    	}	
    	inith -= dm;
    }

    cout << "YES\n";
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