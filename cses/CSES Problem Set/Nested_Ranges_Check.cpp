

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

bool cmp(vector<int>& a, vector<int>& b){
	if(a[0] < b[0]){
		return true;
	}
	else if(a[0] > b[0]){
		return false;
	}
	else{
		if(a[1] > b[1])return true;
		else return false;
	}
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> vp(n);

	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		vp[i] = {x, y, i};
	}

	sort(all(vp), cmp);
	ordset<pair<int,int>> st, st2;
	vector<int> ans(n), ans2(n);


	for(int i = n - 1, j = 0; i >= 0; i--, j++){
		ans[vp[i][2]] = st.order_of_key({vp[i][1] + 1, -1});
		st.insert({vp[i][1], j});
	}



	for(int i = 0; i < n; i++){
		ans2[vp[i][2]] = i - st2.order_of_key({vp[i][1], -1});
		st2.insert({vp[i][1], n - i});
	}

	for(int i = 0; i < n; i++){
		if(ans[i] != 0){
			ans[i] = 1;
		}
		cout << ans[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < n; i++){
		if(ans2[i] != 0){
			ans2[i] = 1;
		}
		cout << ans2[i] << " ";
	}

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