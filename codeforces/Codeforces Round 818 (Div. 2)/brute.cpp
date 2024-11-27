

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

void get(vector<int>& ans){
	for(auto x: ans){
		cout << x << " ";
	}
	cout << "\n";

	if(ans.size() == 1){
		return;
	}

	vector<int> val;
	for(int i = 0; i < ans.size(); i += 2){
		int x = rng() % 2;
		if(x == 0){
			val.push_back(ans[i]);
		}
		else{
			val.push_back(ans[i + 1]);
		}
 	}
 	get(val);
}

void solve() {
    int n = rng() % 5;
    vector<int> ans;
    for(int i = 1; i <= (1 << n); i++){
    	ans.push_back(i);
    }
    shuffle(all(ans), rng);
    get(ans);
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