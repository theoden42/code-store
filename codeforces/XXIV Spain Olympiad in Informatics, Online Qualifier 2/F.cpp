

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a;
    for(int i = 0; i < 4; i++)
	    for(int j = (1 << 15); j >= 1; j--){
	    	if(k % j == 0){
	    		a.push_back(j);
	    		k /= j;
	    		break;
	    	}
	    }
	vector<vector<int>> facs(4);
	for(int i = 0; i < 4; i++){
		vector<int> temp;
		for(int j = 1; j * j <= a[i]; j++) if(a[i] % j == 0){
			temp.push_back(j);
			if(a[i] / j != j){
				temp.push_back(a[i] / j);
			}
		}
		sort(all(temp));
		facs[i] = temp;
	}


	for(int i = 0; i < facs[0].size(); i++){
		for(int j = 0; j < facs[1].size(); j++){
			for(int k = 0; k < facs[2].size(); k++){
				for(int l = 0; l < facs[3].size(); l++){
					int left = facs[0][i] * facs[1][j] * facs[2][k] * facs[3][l];
					int right = (a[0] * a[1] * a[2] * a[3]) / left;
					if(left <= n && right <= m){
						cout << "SI\n";
						return;
					}
				}
			}
		}
	}
	cout << "NO\n";

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