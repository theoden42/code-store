

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
    cin >>  n;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
    	cin >> h[i];
    }

    int sm = 0;
    int l = 0;
    int u = 1e9;

    auto check = [&](int x, vector<int> a){

    	ll sum = 0;
    	sum = accumulate(all(a), 0ll);
    	if(sum < n * x)return false;

    	vector<int> ad(n, 0);

    	for(int i = n - 1; i >= 2; i--){
    		int v1 = 3 * (a[i] / 3);
    		int v2 = (a[i] + ad[i] - x);
    		int x = min(v1, v2);
    		if(x < 0)continue;
    		ad[i - 2] += 2 * (x / 3);
    		ad[i - 1] += x / 3;
    	}


    	for(int i = 0; i < n; i++){
    		if(a[i] + ad[i] < x){
    			return false;
    		}
    	}

    	return true;
    };

    int ind = 0;

    while(l <= u){
    	int mid = l + (u - l) / 2;
    	if(check(mid, h)){
    		ind = mid;
    		l = mid + 1;
    	}
    	else{
    		u = mid - 1;
    	}
    }
    cout << ind << "\n";
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