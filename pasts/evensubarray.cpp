
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

vector<int> ps;

void preprocess(int n){
	int i = 1; 
	ps.push_back(0);
	while(i * i < n){
		ps.push_back(i * i);
		i++;
	}
}

int popcount(int n){
	int count = 0;
	while(n != 0){
		n >>= 1;
		count++;
	}
	return count;
}

void solve() {
    int n;
    cin >> n;
    int mx = (1 << (popcount(n)));
    debug(mx);


    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    vector<int> prefix(n + 1, 0);
    prefix[0] = 0;

    for(int i = 1; i <= n; i++){
    	prefix[i] = (prefix[i - 1] ^ ele[i - 1]);
    }



    vector<int> xrv(mx + 1, 0);
    xrv[0]++;

    int count = 0;
    debug(prefix);

    for(int i = 1; i <= n; i++){
    	int val = prefix[i];

    	for(auto& x: ps){
    		if(x >= mx){
    			break;
    		}
    		int s = (x ^ val);
    		debug(s);
    		count += xrv[s];
    	}
    	xrv[prefix[i]]++;
    }


    int ans = 1ll * (n * (n + 1)) / 2;
    cout << ans - count << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    preprocess(1e6);
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}