

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

int getval(vector<int>& a, int value){
	if(value > a[0])return -1;

	int n = a.size();

	int operation = 0;
	int ans = 0;
	int lastoperation = a[0] - value;

	for(int i = 1; i < n; i++){
		if(a[i] - operation < value){
			return -1;
		}
		if(a[i] - operation - value <= lastoperation){
			lastoperation = a[i] - operation - value;
		}
		else{
			operation += (a[i] - operation) - value - lastoperation;
		}
	}

	return (a[0] - value) + operation;

}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    int l = -1e18;
    int u = 0;

    function<int(int)> check = [&](int value)->int{

    	int ans1 = getval(a, value);
    	reverse(all(a));
    	int ans2 = getval(a, value);
    	reverse(all(a));
    	if(ans1 == -1 && ans2 == -1)return -1;
    	else if(ans1 == -1)return ans2;
    	else if(ans2 == -1)return ans1;
    	else return min(ans1, ans2);

    };

    int val = 0;
    int operation = 0;

    while(l <= u){
    	int mid = l + (u - l) / 2;
    	int x = check(mid);
    	if(x != -1){
    		operation = x;
    		val = mid;
    		l = mid + 1;
    	}
    	else{
    		u = mid - 1;
    	}
    }

    cout << -1 * val + operation << "\n";

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