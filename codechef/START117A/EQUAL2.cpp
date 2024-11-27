

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

#define int long long

vector<int> evenvals, oddvals;
unordered_map<int,int> mp;

void preprocess(){
	for(int i = 1; i <= 1e6 + 5; i++){
		int val = (i * (i + 1)) / 2;
		if(val & 1){
			oddvals.push_back(val);
		} else {
			evenvals.push_back(val);
		}
		mp[val] = i;
	}
}

void solve() {
	int a, b;
	cin >> a >> b;
	int val = abs(a - b);
	if(val == 0){
		cout << 0 << "\n";
		return;
	}
	if(val & 1){
		auto x = *lower_bound(all(oddvals), val);
		cout << mp[x] << "\n";
	} else {
		auto x = *lower_bound(all(evenvals), val);
		cout << mp[x] << "\n";
	}
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    preprocess();
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}