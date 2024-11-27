
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
    ll n, p;
    cin >> n >> p;
    int mx = n;
    int index = 0;
    vector<int> ele(n);
    ll sum = 0;
    sum = accumulate(all(ele), sum);
    p = p % sum;
    ll count = n * (p / sum);
    int j = 0;
    ll s = 0;

    if(p == 0){
    	cout << 1 << " " << count << "\n";
    	return;
    }

    for(int i = 0; i < p; i++){	
    	
    	while(s < p && j < n){
    		s += ele[j];
    		j++;
    	}
    	debug(i, j, s, p);
    	int c = j - i;
    	if(c < mx){
    		c = mx;
    		index = i + 1;
    	}
    	s -= ele[i];
    }
    cout << index << " " << count + mx << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}