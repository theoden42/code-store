

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
    int n, m, h;
    cin >> n >> m >> h;
    vector<pair<pair<int,int>,int>> ranks(n);


    for(int i = 0; i < n; i++){
    	vector<int> x(m);
    	for(int j = 0; j < m; j++){
    		cin >> x[j];
    	}
    	sort(all(x));
    	int count = 0;
    	int sum = 0;
    	int ind = 0;
    	int pen = 0;
    	while(ind < m && sum + x[ind] <= h){
    		sum += x[ind];
    		pen += sum;
    		ind++;
    		count++;
    	}
    	ranks[i] = {{count, pen}, i};
    }

    sort(all(ranks), [&](pair<pair<int,int>, int> a, pair<pair<int,int>, int> b){
    	if(a.first.first > b.first.first)
    		return true;
    	if(a.first.first < b.first.first)
    		return false;

    	if(a.first.second < b.first.second)
    		return true;
    	if(a.first.second > b.first.second)
    		return false;

    	return (a.second < b.second);

     });
    

    for(int i = 0; i < n; i++){
    	if(ranks[i].second == 0){
    		cout << i + 1 << "\n";
    		break;
    	}
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