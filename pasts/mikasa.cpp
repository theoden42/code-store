
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
    return (ans );
}

void solve() {
    int n, m;
    cin >> n >> m;
    if(n > m){
    	cout << 0 << "\n";
    	return;
    }
    int count = 0;
    int val = 0;

    vector<int> b1(32, 0);
    vector<int> b2(32, 0);

    int t1 = n;
    int t2 = m;

    while(n != 0 || m != 0){
    	int a1 = (n & 1);
    	int a2 = (m & 1);
    	b1[count] = (a1);
    	b2[count] = (a2);
    	n >>= 1;
    	m >>= 1;
    	count++;
    }

    int sz = b1.size();
    debug(b1, b2);

   	for(int i = 31; i >= 0; i--){
   		if(b2[i] == 1 && b1[i] == 0){
   			val += binpow(2, i);
   		}
   		else if(b2[i] == 0 && b1[i] == 1){
   			break;
   		}
   	}

   	debug(val);

   	if((t1 ^ val) == t2){
   		int ind = 0;
   		for(int i = 0; i < 32; i++){
   			if(b1[i] == 0 && b2[i] == 0){
   				ind = i;
   				break;
   			}
   		}

   		for(int i = ind - 1; i >= 0; i--){
   			if((val & (1 << i))){
   				val -= binpow(2, i);
   			}
   		}
   		val += binpow(2, ind);
   	}

    cout << val << "\n";

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