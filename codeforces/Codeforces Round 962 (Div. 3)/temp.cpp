

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

long long countSpecialSubarray(int n, vector<int> a){
	map<vector<int>, long long> mp;
	vector<int> temp(201, 0);
	mp[temp] += 1;
	long long ans = 0;
	for(int i = 0; i < n; i++){
		vector<int> p(201);
		int x = a[i];
		for(int j = 2; j * j <= a[i]; j++){
			int count = 0;
			while(x % j == 0){
				count += 1;
				x /= j;
			}
			p[j] += (count & 1);
		}
		if(x != 1){
			p[x] += 1;
			p[x] &= 1;
		}
		ans += mp[p];
		mp[p] += 1;
	}
	return ans;
}

void solve() {
    cout << countSpecialSubarray(3, {4, 3, 12}) << endl;
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