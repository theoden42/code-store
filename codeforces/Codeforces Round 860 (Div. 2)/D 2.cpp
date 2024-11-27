
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds


#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define int long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	int flag = 1;
	for(int i = 0; i < n; i++){
		if(v[i] != 0){
			flag = 0;
			break;
		}
	}

	if(flag){
		cout << "No\n";
		return;
	}

	vector<int> ans;
	multiset<int> mst;

	for(int i = 0; i < n; i++){
		mst.insert(v[i]);
	}


	int sum = 0;

	while(!mst.empty()){
		if(sum <= 0){
			auto it = --mst.end();
			ans.push_back(*it);
			sum += *it;
			mst.erase(it);
		}
		else{
			auto it = mst.begin();
			ans.push_back(*it);
			sum += *it;
			mst.erase(it);
		}
	}

	cout << "Yes\n";
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << "\n";

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