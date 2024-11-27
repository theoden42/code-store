
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
    int count = 0;
    vector<int> ans;
    while(n != 0){
    	int r = (n % 10);
    	if(r == 0){
    		count++;
    		n /= 10;
    		continue;
    	}
    	ans.push_back(r * pow(10, count));
    	count++;
    	n /= 10;
    }
    cout << ans.size() << "\n";
    for(auto& x: ans){
    	cout << x << " ";
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