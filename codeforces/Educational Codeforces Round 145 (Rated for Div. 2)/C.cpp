

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
    int n, k;
    cin >> n >> k;

    vector<int> ans(n, 0);
    int ind = 0;


	int l = 1; 
	int u = k;
	int inx = 0;

	while(l <= u){
		int mid = l + (u - l) / 2;
		int temp = (mid * (mid + 1)) / 2;
		if(temp <= k){
			inx = mid;
			l = mid + 1;
		}
		else{
			u = mid - 1;
		}
	}

	for(int count = 1; count <= inx; count++){
		ans[ind++] = 2;
	}
	k -= (inx * (inx + 1)) / 2;


	if(k != 0){
		ans[ind++] = -2 * (inx - k + 1) + 1;
		k = 0;
	}

    for(int i = ind; i < n; i++){
    	ans[i] = -1000;
    }
    for(auto x: ans){
    	cout << x << " ";
    }
    cout << "\n";
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