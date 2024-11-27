

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
   	vector<int> a(n, 1);
   	vector<vector<int>> q(k);
   	for(int i = 0; i < k; i++){
   		int l, r, m;
   		cin >> l >> r >> m;	
   		l--;
   		r--;
   		q[i] = {m, l, r};
   	}
   	sort(all(q));
   	debug(q);
   	int flag = 0;
   	for(int i = 0; i < k; i++){
   		int l = q[i][1];
   		int r = q[i][2];
   		int m = q[i][0];
   		int f = 0;
   		for(int j = l; j <= r; j++){
   			if(a[j] < m){
   				f = 1;
   				break;
   			}
   		}
   		if(!f){
   			if(m == n){
   				cout << "-1\n";
   				return;
   			} else { 
   				for(int j = l; j <= r; j++){
   					a[j] = m + 1;
   				}
   			}
   		}
   	}

   	for(int i = 0; i < n; i++){
   		cout << a[i] << " \n"[i == n - 1];
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