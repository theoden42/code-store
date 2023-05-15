
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
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector<char> chars;
    set<char> ch;
    for(int i = 0; i < n; i++){
    	if(ch.find(a[i]) == ch.end()){
    		chars.push_back(a[i]);
    		ch.insert(a[i]);
    	}
    }

    int len = chars.size();
    int perms = binpow(2, len);

    ll mx = 0;
   	int lp = -1;
    for(int i = 0; i < n; i++){
    	if(a[i] != b[i]){
    		ll len = (i - lp - 1);
    		mx += (len * (len + 1)) / 2;
  			lp = i;
    	}
    }

    mx += ((n - 1 - lp) * (n - lp)) / 2;

    for(int i = 0; i < perms; i++){
    	int temp = i;
    	multiset<char> mst;
    	for(int j = 0; j < len; j++){
    		if(temp & 1){
    			mst.insert(chars[j]);
    		}
    		temp >>= 1;
    	}
    	if(mst.size() > k)continue;

    	ll ans = 0;
    	int lastpos = -1;
    	for(int j = 0; j < n; j++){
    		if(a[j] != b[j] && mst.find(a[j]) == mst.end()){
    			ll l = (j - lastpos - 1);
    			ans += (1ll * l * (l + 1)) / 2;
    			lastpos = j;
    		}
    	}
	    if(lastpos < n - 1){
			ll l = (n - 1 - lastpos);
			ans += (1ll * l * (l + 1)) / 2;
		}

    	mx = max(mx, ans);
    }
    cout << mx << "\n";
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