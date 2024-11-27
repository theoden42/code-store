
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

int binpow(int a, int b)
{
    int ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a);
        }
        a = (a * a);
        b = b >> 1; 
    }
    return (ans);
}

void solve() {
	int x;
	cin >> x;
	if(x & 1){
		cout << "-1\n";
		return;
	}
	int a = 0;
	int b = 0;

	int nd = x / 2;
	int t = x;

	for(int i = 0; i < 31; i++){

		int v1 = (nd & 1);
		int v2 = (t & 1);

		debug(nd, t);

		if(v1 == 1 && v2 == 0){
			a += binpow(2, i);
			b += binpow(2, i);
		}
		else if(v1 == 0 && v2 == 1){
			a += binpow(2, i);
		}
		else if(v1 == 1 && v2 == 1){
			cout << "-1\n";
			return; 
		}
		nd >>= 1;
		t >>= 1;
	}

	cout << a << " " << b << "\n";

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