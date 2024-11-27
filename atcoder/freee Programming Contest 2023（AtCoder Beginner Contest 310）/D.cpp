

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

#define int int64_t

void solve() {
	int n, t, m;
	cin >> n >> t >> m;
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		incomp[a].push_back(b);
		incomp[b].push_back(a);
	}
	for(int i = 0; i < n; i++){
		sort(all(incomp[i]));
	}

	vector<vector<int>> teams(t);
	int count = 0;

	function<void(int)> numways 
	 = [&](int ind){
		if(ind == n){
			// debug(teams);
			for(int j = 0; j < t; j++){
				if(teams[j].size() == 0)
					return;

				for(int k = 0; k < teams[j].size(); k++){
					for(int l = k + 1; l < teams[j].size(); l++){

					}
				}
			}

			count++;
			return;
		}
		int count = 0;
		for(int j = 0; j < t; j++){
			teams[j].push_back(ind);
			numways(ind + 1);
			teams[j].pop_back();
		}
	};

	numways(0);
	for(int i = 1; i <= t; i++){
		count /= i;
	}
	cout << count << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}