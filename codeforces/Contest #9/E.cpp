

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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    int dis = a[n - 1] - a[0];
    int maxdis = x * (n - 1);
    if(dis <= maxdis){
    	int mx = 0;
    	for(int i = 1; i < n; i++){
    		if(a[i] - a[i - 1] > x){
                int d = a[i] - (a[i - 1] + x);
                mx = max(mx, d);
    			a[i] = a[i - 1] + x;
    		}
    	}
        cout << mx << "\n";
    	for(auto& x: a){
    		cout << x << " ";
    	}
    	cout << "\n";
    }else{
    	int travel = (dis - maxdis + 1) / 2;
    	vector<int> nw(n);
    	nw[0] = a[0];
    	nw[0] += travel;
    	for(int i = 1; i < n; i++){
    		nw[i] = nw[i - 1] + x;
    	}
    	int mx = 0;
    	for(int i = 0; i < n; i++){
    		mx = max(mx, abs(nw[i] - a[i]));
    	}
    	cout << mx << "\n";
    	for(auto& x: nw){
    		cout << x << " ";
    	}
    	cout << endl;
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