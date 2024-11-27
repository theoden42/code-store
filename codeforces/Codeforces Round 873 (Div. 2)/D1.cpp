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

struct node{
	int left;
	int right;
	int leastlement;
	int maxelement;

	void init(int l, int r, int mx, int mn){
		left = l;
		right =  r;
		leastlement = mn;
		maxelement = mx;
	}

	bool contains(int val){
		return (val >= leastlement && val <= maxelement);
	}

};


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    // debug(a);

    ll ans = 0;
    for(int i = 0; i < n; i++){
    	ll last = 0;
    	int mx = 0;
    	stack<node> ranges;

    	for(int j = i; j < n; j++){

    		if(a[j] > mx){
    			node nd;
    			nd.init(j, j, a[j], a[j]);
    			ranges.push(nd);
    		}
    		else{
    			int new_mx = a[j];
    			int new_mn = a[j];
    			while(!ranges.empty() && !(ranges.top().maxelement < a[j])){
    				node x = ranges.top();
    				last -= (x.right - x.left);
    				new_mn = min(x.leastlement, new_mn);
    				new_mx = max(x.maxelement, new_mx);
    				ranges.pop();
    			}

    			if(ranges.empty()){
    				node nd;
    				nd.init(i, j, new_mx, new_mn);
    				// debug(j, i);
    				last += j - i;
    				ranges.push(nd);
    			}
    			else{
    				node x = ranges.top();
    				node nt;
    				nt.init(x.right + 1, j, new_mx, new_mn);
    				ranges.push(nt);
    				last += j - x.right - 1;

    			}

    		}
    		mx = max(mx, a[j]);
    		ans += last;
    		// debug(last, ans);
    	}
    }

    cout << ans << "\n";


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