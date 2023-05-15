
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
    int p, q, r;
    cin >> p >> q >> r;
    int val = (p | q | r);
    vector<int> pbit(21, 0);
    vector<int> qbit(21, 0);
    vector<int> rbit(21, 0);

    for(int i = 0; i < 21; i++){
    	pbit[i] = (p & 1);
    	qbit[i] = (q & 1);
    	rbit[i] = (r & 1);
    	p = p >> 1;
    	q = q >> 1;
    	r = r >> 1;
    }
    ll count = 1;
    for(int i = 0; i < 21; i++){
    	if(pbit[i] == 0 && qbit[i] == 0 && rbit[i] == 0){
    		count *= 1;
    		continue;
    	}
    	if(pbit[i] == 1 && qbit[i] == 1 && rbit[i] == 1){
    		count *= 4;
    		continue;
    	}
    	int l = pbit[i] + qbit[i] + rbit[i];
    	if(l == 1){
    		count = 0;
    		break;
    	}
    	else{
    		count *= 1;
    	}

    }
    cout << count << "\n";
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