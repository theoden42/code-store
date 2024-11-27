
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
	
ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a);
        }
        a = (a * a);
        b = b >> 1; 
    }
    return (ans);
}

int nod(ll x){
	int count = 0;
	while(x != 0){
		count++; 
		x /= 10;
	}
	return count;
}

int largest_digit(ll x){
	int r = 0;
	while(x != 0){
		r = x % 10;
		x /= 10;
	}
	return r;
}

ll count(int digitno, int last_digit, string max, int tight){

	if(digitno == max.size() - 1 ){
		if(tight && last_digit > max[max.size() - 1] - '0'){
			return 0;		}
		else return 1;
	}

	
	ll ans = 0;
	if(!tight){
		ans += 10 * count(digitno + 1, last_digit, max, 0);
	}
	else{
		ans += (max[digitno] - '0') * count(digitno + 1, last_digit, max, 0); 
		ans += count(digitno + 1, last_digit, max, 1);
	}

	return ans;
}


ll f(int digits, ll max){
	int x = nod(max);
	if(digits < x){
		ll ans = 9 * binpow(10, digits - 2);
		return ans;
	}

	ll ans = 0;
	int ld = largest_digit(max);

	for(int i = 1; i <= ld; i++){
		if(i == ld){
			ans += count(1, i, to_string(max), 1);
		}
		else{
			ans += count(1, i, to_string(max), 0);
		}
	}
	debug(digits, ans);
	return ans;
}

ll find(int n){
	// digit dp technique usecase
	if(n < 10)return n + 1;

	int d = nod(n);
	ll count = 10;
	for(int i = 2; i <= d; i++){
		count += f(i, n);
		debug(i, count);
	}
	return count;
}


void solve() {
    ll l, r;
    cin >> l >> r;
	ll s = find(r);
	ll y = find(l - 1);
	debug(s, y);
	cout << s - y << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}