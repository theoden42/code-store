
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
    vector<vector<int>> in(n + 1);
    for(int i = 0; i < n; i++){
    	in[ele[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++){
    	vector<int> indx = in[i];
 		int even = 0;
 		int m1 = 0;
    	for(auto& x: indx){
    		if(x % 2 == even){
    			m1++;
    			even = (even + 1) % 2;
    		}
    	}

    	int m2 = 0;
    	int even2 = 1;
    	for(auto& x: indx){
    		if(x % 2 == even2){
    			m2++;
    			even2 = (even2 + 1) % 2;
    		}
    	}
    	cout << max(m1, m2) << " ";
    }
    cout << "\n";
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
