
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
        	ans = (ans * a);
        }
        a = (a * a);
        b = b >> 1; 
    }
    return ans;
}

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> bit1(64, 0);
	vector<int> bit2(64, 0);
	int count = 0;
	int t1 = n;
	int t2 = x;
	if(n == x){
		cout << n << "\n";
		return;
	}
	while(t1 != 0){
		bit1[count++] = (t1 & 1);
		t1 >>= 1;
	}   
	count = 0;
	while(t2 != 0){
		bit2[count++] = (t2 & 1);
		t2 >>= 1;
	}
	debug(bit1, bit2);
	for(int i = 0; i < 64; i++){
		if(bit1[i] == 0 && bit2[i] == 1){
			cout << "-1\n";
			return;
		}
	}
	int ind = 0;
	for(int i = 63; i >= 0; i--){
		if(bit1[i] == 1 && bit2[i] == 0){
			ind = i;
			break;
		}
	}
	if(bit2[ind + 1] == 1){
		cout << "-1\n";
		return;
	}
	for(int i = ind; i >= 0; i--){
		if(bit2[i] != 0){
			cout << "-1\n";
			return;
		}
	}
	int ans = 0;
	for(int i = 63; i > ind + 1; i--){
		if(bit1[i] != 0){
			ans += binpow(2, i);
		}
	}
	ans += binpow(2, ind + 1);
	cout << ans << "\n";
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