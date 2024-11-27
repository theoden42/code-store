

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
   	int i = 0;	
   	int val = 0;
   	vector<int> ans;
   	for(int i = 1; i <= n; i++){
   		ans.push_back(i);
   	}
   	if(n > 2){
   		swap(ans[0], ans[1]);
   	}
   	for(int i = 0; i < ans.size(); i++){
   		if(i & 1){
   			val |= ans[i];
   		} else {
   			val &= ans[i];
   		}
   	}
   	cout << val << "\n";
   	for(int i = 0; i < ans.size(); i++)
   		cout << ans[i] << " \n"[i == ans.size() - 1];
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