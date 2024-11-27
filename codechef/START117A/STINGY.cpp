

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
    vector<pair<int,int>> vals;
    for(int i = 0; i < n; i++){
    	int j = i;
    	int count = 0;
    	while(j < n && a[j] == a[i]){
    		j += 1;
    		count += 1;
    	}
    	vals.push_back({count, a[i]});
    	i = j - 1;
    }

    int total = 0;
    while(vals.size() > 1){
    	vector<pair<int,int>> temp;
    	for(int i = 0; i < vals.size(); i++){
    		int x = vals[i].first - 1;
    		if(x == 0)
    			continue;
    		if(temp.empty()){
    			temp.push_back({x, vals[i].second});
    		} else if(temp.back().second == vals[i].second){
    			temp.back().first += x;
    		} else{
    			temp.push_back({x, vals[i].second});
    		}
    	}
    	total += 1;
    	vals.assign(all(temp));
    }

    // debug(total);
    // debug(vals);

    if(!vals.empty())
    	total += vals.back().first;

    if(total & 1){
    	cout << "Alice\n";
    } else {
    	cout << "Bob\n";
    }

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