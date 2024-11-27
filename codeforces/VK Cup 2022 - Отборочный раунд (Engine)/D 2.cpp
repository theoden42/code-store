

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

	auto check = [&](int val){
		debug(val);
		int count = 0;
		for(int i = 0; i < n; i++){
			int v = a[i] + val;
			if((int)sqrtl(v) == sqrtl(v)){
				count++;
			}
		}
		return count;
	};


	int mx = 1;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int dif = a[j] - a[i];
			for(int k = 1; k * k <= dif; k++){
				if(dif % k == 0){
					int d = min(k, dif / k);
					int p = (dif / d - d);
					int q = (dif / d + d);

					if(p % 2 == 0 && q % 2 == 0){
						p /= 2;
						q /= 2;
						if(p * p < a[i] || q * q < a[j]){
							continue;
						}
						int x = p * p - a[i];
						mx = max(mx, check(x));
					}
				}
			}
		}
	}
	cout << mx << "\n";
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