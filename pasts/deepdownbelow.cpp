
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
    int m = 0;
    for(int i = 0; i < n; i++){
    	int k;
    	cin >> k;
    	vector<int> ele(k, 0);
    	for(int j = 0; j < k; j++){
    		cin >> ele[j];
    	}
    	sort(ele.begin(), ele.end());
    	m = max(m, ele[k - 1] + 1);
    }
    cout << m << "\n";
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