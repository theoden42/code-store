

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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> vp(n);
    multiset<int> mst1, mst2;
    for(int i = 0; i < n; i++){
    	int l, r;
    	cin >> l >> r;
    	vp[i] = {l, r};
    	if(l == 1){
    		mst1.insert(r);
    	} 
    	if(r == m){
    		mst2.insert(l);
    	}
    }

    debug(mst1, mst2);

    vector<pair<double,int>> pn;
    for(int i = 0; i< n; i++){
    	pn.push_back({vp[i].first - 0.1, 1});
    	pn.push_back({vp[i].second + 0.1, -1});

    }

    sort(all(pn));

    int mx = 0;
    int sum = 0;
    for(int i = 0; i < pn.size(); i++){
    	sum += pn[i].second;
    	while(!mst1.empty() && *mst1.begin() < pn[i].first){
    		mst1.erase(mst1.begin());
    	}
    	int temp = sum - (int)mst1.size();
    	mx = max(mx, temp);
    }

    sum = 0;
    for(int i = pn.size() - 1; i >= 0; i--){
    	sum += -pn[i].second;
    	while(!mst2.empty() && *mst2.rbegin() > pn[i].first){
    		mst2.erase(--mst2.end());
    	}
    	int temp = sum - (int)mst2.size();
    	mx = max(mx, temp);
    }

    cout << mx << "\n";
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