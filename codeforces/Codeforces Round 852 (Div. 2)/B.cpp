
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
	int x, y;
	cin >> x >> y;	
	if(y == x - 1){
		cout << 2 << endl;
		cout << y << " " << x << "\n";
		return;
	}
	else{	

		vector<int> ans;
		ans.push_back(x);
		for(int i = x - 1; i >= y; i--){
			ans.push_back(i);
		}
		for(int i = y + 1; i <= x - 1; i++){
			ans.push_back(i);
		}
		cout << ans.size() << "\n";
		for(auto& x: ans){
			cout << x << " ";
		}
		cout << endl;
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