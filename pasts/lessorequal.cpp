
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
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    int l = 1;
    int u = 1e9;
    while(l <= u){
    	int mid = l + (u - l)/2;
    	int count = 0;
    	for(int i = 0; i < n; i++){
    		if(ele[i] <= mid){
    			count++;
    		}
    	}
    	if(count == k){
    		cout << mid << "\n";
    		return;
    	}
    	else if(count < k){
    		l = mid + 1;
    	}
    	else{
    		u = mid - 1;
    	}
    }
    cout << "-1" << "\n";
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