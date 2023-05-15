
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
    for(int i = 0; i< n; i++){
    	cin >> ele[i];
    }
   	vector<int> ans = ele;
   	sort(ans.begin(), ans.end());
   	vector<ll> p1(n, 0);
   	vector<ll> p2(n, 0);
   	for(int i = 0; i < n; i++){
   		if(i == 0){
   			p1[i] = ele[i];
   			p2[i] = ans[i];
   		}
   		else{
   			p1[i] = p1[i - 1] + ele[i];
   			p2[i] = p2[i - 1] + ans[i];
   		}
   	}
   	int m;
   	cin >> m;
   	for(int i = 0; i < m; i++){
   		int t, l, r;
   		cin >> t >> l >> r;
   		if(t == 1){
   			cout << p1[r - 1] - p1[l - 1] + ele[l - 1] << "\n";
   		}
   		else{
   			cout << p2[r - 1] - p2[l - 1] + ans[l - 1] << "\n";
   		}
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