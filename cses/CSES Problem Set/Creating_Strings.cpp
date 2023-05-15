

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

void recur(int i, int n, string& s, string& str, vector<int>& taken, vector<string>& ans){
	if(i == n){
		ans.push_back(s);
		return;
	}

	for(int j = 0; j < n; j++){
		if(!taken[j]){
			s += str[j];
			taken[j] = 1;
			recur(i + 1, n, s, str, taken, ans);
			taken[j] = 0;
			s = s.substr(0, s.size() - 1);
		}
	}
	return;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> ans;
    vector<int> taken(n);

    string st = "";
    recur(0, n, st, s, taken, ans);
    map<string, int> mp;

    vector<string> ans2;
    for(int i = 0; i < ans.size(); i++){
    	if(mp.find(ans[i]) == mp.end()){
    		ans2.push_back(ans[i]);
    		mp[ans[i]] += 1;
    	}
    }

    sort(all(ans2));

    cout << ans2.size() << "\n";

    for(auto x: ans2){
    	cout << x << "\n";
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