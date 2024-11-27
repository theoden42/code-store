
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n);
    ele.push_back(0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    ele.push_back(1440);


    sort(all(ele));
    int x = 0;
    for(int i = 1; i < n + 2; i++){
    	x += (ele[i] - ele[i - 1]) / 120;
    }
    if(x >= 2){
    	cout << "YES\n";
    }
    else{
    	cout << "NO\n";
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