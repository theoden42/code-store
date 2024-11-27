

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
    vector<vector<pair<int,int>>> v(37);
    vector<int> count(n);
    for(int i = 0; i < n; i++){
    	int c;
    	cin >> c;
    	for(int j = 0; j < c; j++){
    		int x;
    		cin >> x;
    		v[x].push_back({c, i});
    	}
    	count[i] = c;
    }

    int x;
    cin >> x;


    sort(all(v[x]));

    vector<int> ans;
    for(int i = 0; i < v[x].size(); i++){
    	if(i == 0 || v[x][i - 1].first == v[x][i].first){
    		ans.push_back(v[x][i].second + 1);
    	}
    }
    // debug(ans);

    cout << ans.size();
    cout << "\n";
    for(auto& a: ans){
    	cout << a << " ";
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