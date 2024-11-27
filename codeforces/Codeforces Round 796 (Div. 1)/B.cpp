

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

int query(vector<int>& a){
	string s = "";
	for(auto x: a){
		s += (char)('0' + x);
	}
	cout << "? " << s << endl;
	int n;
	cin >> n;
	return n;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> edges;
    vector<int> state(m);
    for(int i = 0; i < m; i++){
    	state[i] = 1;
    	int val = query(state);
    	state[i] = 0;
    	edges.push_back(val);
    }
    vector<pair<int,int>> temp(m);
    for(int i = 0; i < m; i++){
    	temp[i] = {edges[i], i};
    }
    sort(all(temp));
    int initial = 0;
    int ans = 0;
    int index = 0;	
    for(int i = 0; i < m; i++){
    	int edgenum = temp[i].second;
    	state[edgenum] = 1;
    	int nval = query(state);
    	if(nval == initial + temp[i].first){
    		ans += temp[i].first;
    		initial = nval;
    	} else {
    		state[edgenum] = 0;
    	}
    }

    cout << "! " << ans << endl;

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