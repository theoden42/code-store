
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
    int d12, d23, d31;
    cin >> d12 >> d23 >> d31;
    if(d12 == d23 + d31){
    	cout << "YES" << "\n";
    	map<int,int> mp;
    	int k = 0;
    	
    }
    else if(d23 == d12 + d31){
    	cout << "YES" << "\n";
    }
    else if(d31 == d12 + d23){
    	cout << "YES" << "\n";
    }
    else{
    	cout << "NO" << "\n";
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