
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
    ll n, s;
    cin >> n >> s;
    vector<ll> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    int i = 0; int j = 0;
    ll sum = 0;
    int mx = 0;

    while(i < n && j < n){
    	if(i > j){
    		j = i;
    	}
    	sum += ele[j];
    	debug(i, j);
    	if(sum > s){
    		while(sum > s){
    			sum -= ele[i];
    			i++;
    		}
            mx = max(j - i + 1, mx);
            j++;
    	}
    	else{
    		mx = max(mx, j - i + 1);
    		j++;
    	}
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