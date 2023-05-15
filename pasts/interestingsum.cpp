
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
    int n;
    cin >> n;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<int> temp = ele;
    sort(all(temp));
 	int fmax = -1;
 	int lmax = -1;
 	int fmin = -1;
 	int lmin = -1;
 	for(int i = 0; i < n; i++){
 		if(ele[i] == temp[0]){
 			lmin = i;
 			if(fmin == -1){
 				fmin = i;
 			}
 		}
 		else if(ele[i] == temp[n - 1]){
 			lmax = i;
 			if(fmax == -1){
 				fmax = i;
 			}
 		}
 	}
 	int mx = 0;
 	int mi = 1e9 + 5;
 	for(int i = fmin + 1; i < lmax; i++){
 		if(ele[i] > mx){
 			mx = ele[i];
 		}
 		if(ele[i] < mi){
 			mi = ele[i];
 		}
 	}
 	int val = ele[n - 1] - ele[0] + mx - mi;
 	for(int i = fmax + 1; i < lmin; i++){
 		if(ele[i] > mx){
 			mx = ele[i];
 		}
 		if(ele[i] < mi){
 			mi = ele[i];
 		}
 	}
 	val = max(val, ele[n - 1] - ele[0] + mx - mi);

 	cout << val << "\n";
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