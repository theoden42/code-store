

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

bool cmp(pair<int,int> p1, pair<int,int> p2){
	if(p2.second < p1.second)return false;
	if(p2.second > p1.second)return true;
	if(p1.first > p2.first)return false;
	else return true;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> vp(n);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		vp[i] = {x, y};
	}
	sort(all(vp), cmp);	
	int count = 0;

	debug(vp);

	multiset<int> mst;
	for(int i = 0; i < n; i++){
		debug(mst, count);
		int st = vp[i].first;
		auto it = mst.upper_bound(st);
		if(it != mst.begin()){
			it--;
			mst.erase(it);
			mst.insert(vp[i].second);
			count++;
		}
		else if(mst.size() < k){
			count++;
			mst.insert(vp[i].second);
		}
	}
	cout << count << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}	