

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
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}

	ll l = *max_element(all(a));
	ll u = 1e15;
	ll ans = 1e15;

	auto check = [&](ll val){
		int count = 1;
		ll sum = a[0];
		for(int i = 1; i < n; i++){

			if(sum + a[i] > val){
				count++;
				sum = a[i];
			}
			else{
				sum += a[i];	
			}
		}

		if(count <= k){
			return true;
		}
		else{
			return false;
		}
	};

	while(l <= u){
		ll mid = (l + u) / 2;
		if(check(mid)){
			ans = mid;
			u = mid - 1;
		}else{
			l = mid + 1;
		}
	}

	cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}	