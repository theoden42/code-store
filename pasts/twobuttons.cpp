
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
    int n, m;
    cin >> n >> m;
    if(m < n){
    	cout << n - m << "\n";
    }
    else {
    	int tn = n;
    	int count1 = 0;
    	while(tn < m){
    		tn = tn * 2;
    		count1 += 1;
    	}
    	count1 += tn - m;
 		int count2 = 0;
 		int f = m;
 		while(f > n){
 			if(f % 2 != 0){
 				f++;
 				count2++;
 				continue;
 			}
 			f /= 2;
 			count2++;
 		}
 		count2 += n - f;
 		cout << min(count1, count2) << "\n";
    }
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