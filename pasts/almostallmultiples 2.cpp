
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

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}

void solve() {
    int n, x;
    cin >> n >> x;
    if(n % x != 0){
    	cout << "-1\n";
    	return;
    }

    vector<int> ans(n + 1);
    ans[x] = n;
    ans[1] = x;
    ans[n] = 1;
    for(int i = 2 ; i <= n - 1; i++){
    	if(i != x)
    		ans[i] = i;
    }

    int ind = x;
    int val = n;
    while(ind < n){
    	int f = 0;
    	for(int i = 2; i <= n / ind; i++){
    		int temp = ind * i;
    		if(n % temp == 0 && temp < n){
    			f = 1;
    			swap(ans[ind], ans[temp]);
    			ind = temp;
    			break;
    		}
    	}
    	if(!f)break;
    }

   	for(int i = 1; i <= n; i++){
   		cout << ans[i] << " ";
   	}
   	cout << "\n";

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