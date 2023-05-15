

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
	int n;
	cin >> n;
	vector<vector<int>> vp(n);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		vp[i] = {x, y, i};
	}

	sort(all(vp));

	set<int> free;
	free.insert(1);
	vector<int> ans(n);
	int mx = 2;

	ordset<pair<int,int>> st;

	for(int i = 0; i < n; i++){
		int ar = vp[i][0];
		// how many departing before this? 
		int count = st.order_of_key({ar, 0});
		while(count != 0){
			int rm = (st.begin())->second;
			free.insert(rm);
			st.erase(st.begin());
			count--;
		}
		if(free.size() == 0){
			free.insert(mx);
			mx++;
		}
		int al = *free.begin();
		free.erase(free.begin());
		ans[vp[i][2]] = al;
		st.insert({vp[i][1], al});
	}

	cout << mx - 1 << "\n";
	for(int i = 0; i < n; ++i){
		cout << ans[i] << " ";
	}
	cout << "\n";
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