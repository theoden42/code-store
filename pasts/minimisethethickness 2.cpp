
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
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
	ll sum = 0;
	sum = accumulate(all(ele), sum);

	int mn = n;



	for(int i = 1; i * i <= sum; i++){
		if(sum % i == 0){

			ll c = 0;
			int sz = 0;
			int mx = 0;


			for(int j = 0; j < n; j++){
				c += ele[j];
				sz++;
				if(c == i){
					mx = max(mx, sz);
					sz = 0;
					c = 0;
				}
				else if(c > i){
					mx = -1;
					break;
				}
			}	
			if(mx != -1 && c == 0){
				mn = min(mn, mx);
			}

			c = 0;
			sz = 0;
			mx = 0;

			for(int j = 0; j < n; j++){
				c += ele[j];
				sz++;
				if(c == (sum / i)){
					mx = max(mx, sz);
					sz = 0;
					c = 0;
				}
				else if(c > sum / i){
					mx = -1;
					break;
				}
			}
			if(mx != -1 && c == 0){
				mn = min(mn, mx);
			}
		}
	}
	cout << mn << "\n";
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