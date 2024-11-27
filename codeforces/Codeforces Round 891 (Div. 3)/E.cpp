

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


void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> pn(n);
    vector<int> terms(n - 1);

    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	pn[i] = {x, i};
    }

    sort(all(pn));
    vector<int> x;
    vector<int> ind;
    for(auto [pn1, pn2]: pn){
    	x.push_back(pn1);
    	ind.push_back(pn2);
    }

    for(int i = 0; i < n - 1; i++){
    	if(i == 0){
    		terms[i] = (x[i + 1] - x[i] + 1) * (n - 1);
    	} else {
    		terms[i] = (x[i + 1] - x[i]) * (n - 1 - i);
     	}
    }

    // debug(terms);
    vector<int> ans(n);

    int sum = 0;
    sum = accumulate(all(terms), 0ll);
    ans[ind[0]] = sum + 1;	

    for(int i = 1; i < n; i++){
    	sum -= (x[i] - x[i - 1]) * (n - i);
    	sum += ((x[i] - x[i - 1])) * (i);
    	// sum += (n - 1 - i);
    	ans[ind[i]] = sum + 1;
    }

    for(auto x: ans){
    	cout << x << " ";
    }
    cout << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}