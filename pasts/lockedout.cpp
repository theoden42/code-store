
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
	int n, k;
    cin >> n >> k;
    vector<string> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
   	vector<int> perm(k, 0);
   	for(int i = 0; i < k; i++){
   		perm[i] = i;
   	}
   	vector<ll> vals(n, 0);
   	ll miin = 1e11;
   	do {
   		for(int i = 0; i < n; i++){
   			vals[i] = 0;
   		}
   		for(int i = 0; i < n; i++){
   			for(int j = 0; j < k; j++){
   			 	vals[i] = vals[i] * 10 + (ele[i][perm[j]] - '0');
   			}
   		}
   		ll mi = 1e11;
   		ll mx = 0;
   		for(int i = 0; i < n; i++){
   			if(vals[i] < mi){
   				mi = vals[i];
   			}
   			if(vals[i] > mx){
   				mx = vals[i];
   			}
   		}
   		ll x = mx - mi;
   		miin = min(x, miin);
   	}
   	while(next_permutation(all(perm)));
   	cout << miin << "\n";
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