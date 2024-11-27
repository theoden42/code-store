
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
	int n = 5;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	ele[i] = i + 1;
    }
    for(int i = 0; i < n; i++){
    	cout << ele[i] << " ";
    }
    cout << endl;
    for(auto& x: ele){
    	x = x - 2;
    }
    for(int i = 0; i < n; i++){
    	cout << ele[i] << " ";
    }
    cout << endl;
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