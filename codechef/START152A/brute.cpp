

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
	for(int i = 2; i <= 6; i += 2){
		vector<int> perm(i);
		for(int j = 0; j < i; j++){
			perm[j] = j + 1;
		}
		debug(perm);
		int mx = 0;	
		vector<vector<int>> perms;
		do{
			int sum = 0;
			for(int j = 0; j < i; j += 2){
				sum += abs(perm[j] - perm[j + 1]);
			}
			if(sum > mx){
				perms.clear();
				mx = sum;
			} else if(sum == mx){
				perms.push_back(perm);
			}
		} while(next_permutation(all(perm)));

		debug(i, mx, perms);
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