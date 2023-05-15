
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
    vector<int> prefix(n, 0);
    for(int i = 0; i < n; i++){
    	if(i == 0){
    		prefix[i] = ele[i];
    		continue;
    	}
    	prefix[i] = prefix[i - 1] + ele[i];
    }
    // for(int i = 0; i < n; i++){
    // 	cout << prefix[i] << " ";
    // }
    // cout << "\n";
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
    	int x;
    	cin >> x;
    	int index = -1;
    	int l = 0;
    	int u = n - 1;
    	while(l <= u){
    		int mid = l + (u - l) / 2;
    		if(prefix[mid] >= x){
    			index = mid;
    			u = mid - 1;
    		}
    		else{
    			l = mid + 1;
    		}
    	}
    	cout << index + 1 << "\n";
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