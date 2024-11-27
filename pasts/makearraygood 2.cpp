
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
#define int long long 

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> ele(n);
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	ele[i] = {x, i + 1};
    }


    debug(ele);
    sort(all(ele));
    vector<pair<int,int>> ans;
	for(int i = 1; i < n; i++){
		int x = ele[i].first;
		int y = ele[i - 1].first;
		int val = (y - x % y) % y;
		debug(ele[i].second, val);
		ele[i].first = ele[i].first + val;
		ans.push_back({ele[i].second, val});
	}

	cout << ans.size() << "\n";
	for(auto& x: ans){
		cout << x.first<< " " << x.second<< "\n";
	}

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}