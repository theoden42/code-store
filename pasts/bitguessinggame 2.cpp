
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

int query(int x){
	cout << "- " << x << endl;
	int cnt;
	cin >> cnt;
	if(cnt == -1){
		exit(0);
	}
	return cnt;
}

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) ;
        }
        a = (a * a) ;
        b = b >> 1; 
    }
    return (ans);
}

void solve() {
	int cnt;
	cin >> cnt;
	int ans = 0;
	int flag = 0;
	int extra = 0;

	for(int i = 0; i < 30 && cnt > 0; i++){
		int temp;
		if(!flag)
			temp = query(binpow(2, i));
		else 
			temp = query(binpow(2, i) + extra);


		if(temp == cnt - 1){
			ans += binpow(2, i);
			cnt = temp;
			flag = 0;
		}
		else{
			int inc = temp - cnt;
			assert(inc >= 0);
			extra = 0;
			for(int j = i; j <= i + inc; j++){
				extra += binpow(2, j);
			}
			ans += binpow(2, i + inc + 1);

			i = i + inc + 1;
			cnt--;
			flag = 1;
		}
	}
	// if(cnt == 1){
	// 	ans += binpow(2, 30);
	// }
	
	cout << "! " << ans << endl;
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