

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
	vector<int> a(n), b(n);


	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	int s1 = accumulate(all(a), 0);
	int s2 = accumulate(all(b), 0);
	if(s1 != s2){
		cout << "-1\n";
		return;
	}

	vector<pair<int,int>> neg, pos;	

	for(int i = 0; i < n; i++){
		if(a[i] > b[i]){
			pos.push_back({i, a[i] - b[i]});
		}
		if(a[i] < b[i]){
			neg.push_back({i, b[i] - a[i]});
		}
	}	


	// debug(pos, neg);

	vector<pair<int,int>> ans;

	while(!neg.empty() && !pos.empty()){
		// debug(pos, neg);
		// debug(ans);
		auto& p = pos.back();
		auto& n = neg.back();

		if(n.second == 0){
			neg.pop_back();
			continue;
		}

		if(p.second == 0){
			pos.pop_back();
			continue;
		}

		if(p.second <= n.second){
			for(int i = 1; i <= p.second; i++){
				ans.push_back({p.first + 1, n.first + 1});
			}
			n.second -= p.second;
			pos.pop_back();
		}
		else{
			for(int i = 1; i <= n.second; i++){
				ans.push_back({p.first + 1, n.first + 1});
			}
			p.second -= n.second;
			neg.pop_back();
		}
	}

	cout << ans.size() << "\n";
	for(auto x: ans){
		cout << x.first << " " << x.second << "\n";
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