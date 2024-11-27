

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
const ll INF = 1e18;

#define int long long

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n + 2);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }	


    int mn = INF;
    int ind = -1;
    a[n + 1] = d + 1;
    multiset<int> mst;
    int count = 0;

    for(int i = 1; i <= n; i++){
    	int time = a[i] - a[i - 1] - 1;
    	if(time <  mn){
    		ind = i;
    		mn = time;
    		count = 0;
    	}
    	if(time == mn){
    		count++;
    	}
    	mst.insert(time);
    }

    if(count > 1){
    	cout << mn << "\n";
    	return;
    }

    if(ind == n){
    	mst.erase(mst.find(a[ind] - a[ind - 1]));
    }
    else{
    	mst.erase(mst.find(a[ind + 1] - a[ind]));
    	mst.erase(mst.find(a[ind] - a[ind - 1]));
    }

    int ans = mn;

    

    for(int i = 0; i < n; i++){
    	// I am putting this at the best place between i and 
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