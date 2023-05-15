
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
    vector<int> perm(n + 1);
    for(int i = 1; i <= n; i++){
    	perm[i] = i;
    }
    cout << n << "\n";
    for(int j = 1; j <= n; j++){
    	cout << perm[j] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= n - 1; i++){
    	int t = perm[i];
    	perm[i] = perm[n];
    	perm[n] = t;
    	for(int j = 1; j <= n; j++){
    		cout << perm[j] << " ";
    	}
    	cout << "\n";
    }
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