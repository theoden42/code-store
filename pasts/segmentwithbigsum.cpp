
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
	int n;
	cin >> n;
	ll s;
	cin >> s;
	vector<ll> ele(n, 0);
	for(int i = 0; i < n; i++){
		cin >> ele[i];
	}
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sum += ele[i];
	}
	if(sum < s){
		cout << -1 << "\n";
		return;
 	}
 	sum = 0;
	int mn = n;
	int j = -1;
    for(int i = 0; i < n; i++){
    	while(sum < s && j < n - 1){
    		j++;
    		sum += ele[j];
    	}
    	if(sum >= s){
    		mn = min(mn, j - i + 1);
    		sum -= ele[i];
    	}
    	else{
    		break;
    	}
    }

    cout << mn << "\n";
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