
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
    int k, n;
    cin >> n >> k;	
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(ele[i]);
    }
    if(s.size() > k){
        cout << -1 << "\n";
        return;
    }
    cout << n * k << "\n";
    for(int i = 0; i < n; i++){
        for(int b: s){
            cout << b << " ";
        }
        for(int j = 0; j < k - (int)s.size(); j++){
            cout << 1 << " ";
        }
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