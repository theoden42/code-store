

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
    int n, b, x;
    cin >> n >> b >> x;
    vector<int> c(n);
    for(int i = 0; i < n; i++){
    	cin >> c[i];
    }

    int val = *max_element(all(c));
    int mx = 0;

   	vector<pair<int,int>> v;
   	for(int i = 0; i < n; i++){
   		v.push_back({c[i], i});
   	}
   	sort(all(v));
   	reverse(all(v));

   	vector<int> sum(n, 0);
    int curr = 0;

    for(int j = 1; j <= val; j++){
   		while(!v.empty() && v.back().first < j)
   			v.pop_back();

   		for(auto [x, i]: v){
   			curr -= sum[i];

   			int k = j;
   			int rem = c[i] % k;

            int v1 = (c[i] - rem) * (k - 1) * ((c[i] - rem) / k);
	    	v1 /= 2;

            int v2 = rem * (c[i] - rem) - rem * ((c[i] - rem) / k);
	    	v2 += (rem * (rem - 1)) / 2;
	    	sum[i] = v1 + v2;

	    	curr += sum[i];
   		}

        int total = b * curr - (j - 1) * x;
   		mx = max(mx, total);
    }

    cout << (int)mx << "\n";
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