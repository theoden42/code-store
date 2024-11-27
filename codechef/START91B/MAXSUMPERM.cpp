

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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    sort(all(a));
    vector<int> D(n + 1, 0);


    for(int i = 1; i <= q; i++){
    	int l, r;
    	cin >> l >> r;
    	l--;
    	r--;

    	debug(l, r);

    	D[l] += 1;
		D[r + 1] -= 1;
    }

    vector<int> occur(n);
    for(int i = 0; i < n; i++){
    	if(i == 0)occur[i] = D[0];
    	else{
    		occur[i] = D[i] + occur[i - 1];
    	}
    }

    multiset<pair<int,int>> mst;
    for(int i = 0; i < n; i++){
    	mst.insert({occur[i], i});
    }
    vector<int> ans(n);

    int count = n - 1;
    while(!mst.empty()){
    	auto it = --mst.end();
    	int ind = it->second;
    	ans[ind] = a[count--];
    	mst.erase(it);
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
    	sum += (ans[i] * occur[i]);
    }
    cout << sum << "\n";	
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