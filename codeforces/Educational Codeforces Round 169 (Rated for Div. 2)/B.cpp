

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
	vector<pair<int,int>> vp(2);
	for(int i = 0; i < 2; i++)
		cin >> vp[i].first >> vp[i].second;

	sort(all(vp));	
	if(vp[0].second < vp[1].first){
		cout << "1\n";
		return;
	}
	int len = min(vp[0].second, vp[1].second) - vp[1].first;
	if(vp[0].first < vp[1].first) 
		len += 1;
	if(min(vp[0].second, vp[1].second) < max(vp[0].second, vp[1].second))
		len += 1;

	cout << len << "\n";

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