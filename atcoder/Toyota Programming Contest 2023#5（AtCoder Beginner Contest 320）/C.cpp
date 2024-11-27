

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
	int m;
	cin >> m;
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	int mx = 1e9;

	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < m; k++){
				int time = 0;
				if(s1[i] == s2[j] && s2[j] == s3[k]){
					if(i != j && j != k && i != k){
						time = max({i, j, k});
					} else if(i == j && j == k){
						time = 2 * m + i;
					} else if(i == j){
						time = m + i;
					} else if(j == k){
						time = m + k;
					} else { 
						time = m + k;
					}
					mx = min(mx, time);
				}
			}
		}
	}

	if(mx == 1e9)
		cout << "-1\n";
	else 
		cout << mx << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}