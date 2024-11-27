
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

    int n, q;
    cin >> n >> q;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    vector<int> xorr(n, 0);
    xorr[0] = ele[0];
    for(int i = 1; i < n; i++){
    	xorr[i] = (xorr[i - 1] ^ ele[i]);
    }
    auto findxor = [&](int i, int j){
    	return (xorr[j] ^ xorr[i] ^ ele[i]);
    };


    for(int i = 1; i <= q; i++){
    	int a, b;
    	cin >> a >> b;
		int len = abs(a - b) + 1;
		if(len & 1){
			if(findxor(a, b) == 0){
				cout << "1\n";
			}
			else{
				cout << "2\n";
			}
		}
		else{
			
		}
    }
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