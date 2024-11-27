

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

	int n, m;
	cin >> n >> m;
	int ind = 0;
	vector<string> g(n);
	for(int i = 0; i < n; i++){
		cin >> g[i];
	}
	vector<char> v = {'v', 'i', 'k', 'a'};

	for(int i = 0; i < m; i++){
		if(ind > 3){
			cout << "YES\n";
			return;
		}
		for(int j = 0; j < n; j++){
			if(g[j][i] == v[ind]){
				ind++;
				break;
			}
		}
	}
	if(ind > 3){
		cout << "YES\n";
	} else {
		cout << "NO\n";
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