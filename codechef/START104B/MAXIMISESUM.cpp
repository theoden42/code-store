

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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    multiset<pair<int,int>> mst;
    for(int i = 0; i < n; i++){
    	mst.insert({-a[i], i});
    }

    int mx = 0;
    int mxind = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] > mx){
    		mx = a[i];
    		mxind = i;	
    	}
    }

    int i = mxind;
    int j = mxind;
    int sum = mx;
    while(!mst.empty()){
    	auto ind = *mst.begin();
    	mst.erase(mst.begin());
    	if(ind.second >= i && ind.second <= j)
    		continue;
    	else if(ind.second < i){
    		int val = -ind.first;
    		int num = i - ind.second;
    		sum += val * num;
    		i = ind.second;
    	} else if(ind.second > j){
    		int val = -ind.first;
    		int num = ind.second - j;
    		sum += val * num;
    		j = ind.second;
    	}
    }

    cout << sum << "\n";
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