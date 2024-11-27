
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
 	sort(all(ele));
 	ll m = ele[n - 1] - ele[0];
 	ll a = 1;
 	ll b = 1;
 	for(int i = 1; i < n - 1; i++){
 		if(ele[i] == ele[i - 1]){
 			a++;
 		}
 		else{
 			break;
 		}
 	}
 	int flag = 0;
 	for(int i = 1; i < n; i++){
 		if(ele[i] != ele[i - 1]){
 			flag = 1;
 			break;
 		}
 	}
 	if(flag == 0){
 		cout << 0 << " ";
 		cout << (1ll * n * (n - 1))/2 << "\n";
 		return;
 	}
 	for(int i = n - 2; i >= 0; i--){
 		if(ele[i] == ele[i + 1]){
 			b++;
 		}
 		else{
 			break;
 		}
 	}
 	cout << m << " ";
 	cout << 1ll * a * b << "\n";
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