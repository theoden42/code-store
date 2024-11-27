

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
    string s;
    cin >> s;
   	vector<int> preone(n + 1);
   	vector<int> prezero(n + 1), diff(n + 1);

   	for(int i = 1; i <= n; i++){
   		preone[i] += preone[i - 1];
   		preone[i] += (s[i - 1] == '1');
   		prezero[i] += prezero[i - 1];
   		prezero[i] += (s[i - 1] == '0');
   	}
   	for(int i = 1; i <= n; i++){
   		diff[i] += preone[i] - prezero[i];
   	}

   	auto check = [&](int md){
   		int r = preone[n] - md;
   		int l = md - prezero[n];
   		// debug(l, r, md);
   		multiset<int> mst;
   		mst.insert(0);
   		for(int i = 1; i <= n; i++){
   			mst.insert(diff[i]);
   			if(i >= k + 1){
   				mst.erase(mst.find(diff[i - k - 1]));
   			}
   			// debug(i, mst);
   			int x = diff[i];
   			auto it = mst.lower_bound(x - r);
   			if(it != mst.end() && *it <= x - l)
   				return true;
   		}

   		return false;
   	};

   	int lb = 0;
   	int ub = n / 2;
   	int ans = 0;
   	while(lb <= ub){
   		int mid = lb + (ub - lb) / 2;
   		if(check(mid)){
   			ans = mid;
   			lb = mid + 1;
   		} else {
   			ub = mid - 1;
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