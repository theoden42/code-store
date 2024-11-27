
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
    int mx = 0;
    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n; j++){
    		int sum = ele[i] + ele[j];
    		int count = 0;
    		int l = i; int u = j;
    		while(l < u){
    			if(ele[l] + ele[u] == sum){
    				count++;
    				l++;
    				u--;
    			}
    			else if(ele[l] + ele[u] < sum){
    				l++;
    			}
    			else{
    				u--;
    			}
    		}
    		mx = max(mx, count);
    	}
    }
    cout << mx << "\n";
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