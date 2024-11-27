

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
    vector<vector<int>> adj1(n, vector<int>(n)), adj2(n, vector<int>(n));
    int mg;
    cin >> mg;
    for(int i = 0; i < mg; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	adj1[u][v] = 1;
    	adj1[v][u] = 1;
    }
    int mh;
    cin >> mh;
    for(int i = 0; i < mh; i++){
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	adj2[a][b] = 1;
    	adj2[b][a] = 1;
    }

    vector<int> perm(n);
    for(int i = 0; i < n; i++)perm[i] = i;
    vector<vector<int>> A(n, vector<int>(n));
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			cin >> A[i][j];
		}
	}

	int ans = 1e18;
	do{
		int cost = 0;
		for(int i = 0; i < n - 1; i++){
			for(int j = i + 1; j < n; j++){
				int a = perm[i];
				int b = perm[j];
				if(a > b)
					swap(a, b);
				if(adj1[i][j] != adj2[a][b])
					cost += A[a][b];
			}
		}
		ans = min(ans, cost);
		// debug(cost, perm);
	} while(next_permutation(all(perm)));
	cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}