
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ele(n, 0);
    for(int i = 0; i < m; i++){
    	int x;
    	cin >> x;
    	ele[x - 1]++;
    }
    sort(ele.begin(), ele.end());
    int l = 1;
    int r = m;
    int ans = m;
    while(l <= r){
    	int a = 0;
    	int b = 0;
    	int mid = l + (r - l) / 2;
    	for(int i = 0; i < n; i++){
    		if(ele[i] < mid){
    			a += (mid - ele[i]) / 2;
    		}
    		else{
    			b += (ele[i] - mid);
    		}
    	}
    	if(a >= b){
    		ans = mid;
    		r = mid - 1;
    	}
    	else{
    		l = mid + 1;
    	}
    }
    cout << ans << "\n";
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
