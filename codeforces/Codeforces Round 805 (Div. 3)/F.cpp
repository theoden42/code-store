

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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }

    multiset<int> msta, mstb;

    for(int i = 0; i < n; i++){
    	while(!(a[i] & 1)){
    		a[i] /= 2;
    	}
    	msta.insert(a[i]);
    	while(!(b[i] & 1)){
    		b[i] /= 2;
    	}
    	mstb.insert(b[i]);
    }

    // debug(msta, mstb);

    while(!mstb.empty()){
    	auto x = *(--mstb.end());

    	while(x != 0){
    		if(msta.find(x) != msta.end()){
    			msta.erase(msta.find(x));
    			break;
    		}
    		x /= 2;
    	}
    	if(x == 0){
    		cout << "NO\n";
    		return;
    	}
    	mstb.erase(--mstb.end());
    }
    cout << "YES\n";
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