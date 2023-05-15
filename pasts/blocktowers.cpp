
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
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n);
    multiset<int> st;

    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }	
    debug(ele);
    
    for(int i = 1; i < n; i++){
    	st.insert(ele[i]);
    }

    debug(st);

    ll x = ele[0];
    for(auto& y: st){
    	if(y <= x)continue;
    	else{
    		int val = (y - x + 1) / 2;
    		x += val;
    	}
    }

    cout << x << "\n";

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