

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
    for(int i = 0; i < n; i++) { 
    	cin >> a[i];
   	}
   	sort(all(a));

   	if(n == 5) { 
   		double l1 = (a[0] + a[2]) / 2.0;
   		double l2 = (a[0] + a[1]) / 2.0;
   		double r1 = (a[3] + a[4]) / 2.0;
   		double r2 = (a[2] + a[4]) / 2.0;
   		double dist1 = r1 - l1;
   		double dist2 = r2 - l2;
   		cout << setprecision(10) << max(dist1, dist2) << "\n";
   		return;
   	}

   	double leftpoint = (a[0] + a[1]) / 2.0;
   	double rightpoint = (a[n - 1] + a[n - 2]) / 2.0;
   	double mxdist = rightpoint - leftpoint;

   	cout << fixed << setprecision(15) <<  mxdist << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}