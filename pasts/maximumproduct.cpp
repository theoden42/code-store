
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define int long long

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
    vector<int> neg;
    vector<int> p;
    for(int i = 0; i < n; i++){
    	if(ele[i] < 0){
    		neg.push_back(-1 * ele[i]);
    	}
    	else{
    		p.push_back(ele[i]);
    	}
    }
    sort(all(ele));
    sort(all(neg));
    sort(all(p));
    int v1 = -3e17;
   	int v2 = -3e17;
   	int v3 = -3e17;
   	if(neg.size() >= 2 && p.size() >= 3){
   		v1 = neg[neg.size() - 1] * neg[neg.size() - 2] * p[p.size() - 1] * p[p.size() - 2] * p[p.size() - 3];

   	}
   	if(neg.size() >= 4 && p.size() >= 1){
   		v2 = neg[neg.size() - 1] * neg[neg.size() - 2] * neg[neg.size() - 3] * neg[neg.size() - 4] * p[p.size() - 1];
   	}
   	v3 = 1;
   	for(int i = n - 5; i <= n - 1; i++){
   		v3 *= ele[i];
   	}
   	//cout << v1 << " " << v2 << " " << v3 << "\n";
   	cout << max({v1, v2, v3}) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}