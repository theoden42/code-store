
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
    int q;
    cin >> q;
    debug(q);
    vector<int> ele(3);
    for(int i = 1; i <= q; i++){
    	cin >> ele[0] >> ele[1] >> ele[2];
        debug(ele);
    	sort(all(ele));
    	int dist = ele[1] - ele[0] + ele[2] - ele[1] + ele[2] - ele[0];
    	if(dist == 0){
    		cout << 0 << "\n";
    	}
    	else if(ele[0] == ele[1] || ele[1] == ele[2]){
    		cout << max(0, dist - 4) << "\n";
    	}
    	else{
    		cout << max(0, dist - 4) << "\n";
    	}
    }
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