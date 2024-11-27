
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
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
    	cin >> p[i];
    }
    sort(all(p));
    vector<ll> prefix(n, 0);
    prefix[0] = p[0];
    for(int i = 1; i < n; i++){
    	prefix[i] = p[i] + prefix[i - 1];
    }

    int l = p[0];
    int u = p[n - 1];
    int mn = 1e15;
    while(l <= u){
    	int mid = l + (u - l)/ 2;
    	auto x = upper_bound(all(p), mid);
    	int in = x - p.begin();
    	if(in != 0 && in != n){
    		int x = prefix[in - 1] ;
    		int y = prefix[n - 1] - x;
    		int a = in * x - a;
    		int b = b - (n - in) * x;
    		mn = min(mn, a + b);
    		if(a > b){
    			u = mid - 1;
    		}
    		else{
    			l = mid + 1;
    		}
    	}
    	if(in == 0){
    		int b = 
    	}
    }

    cout << mn << "\n";

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