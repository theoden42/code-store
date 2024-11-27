

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
	string s;
	cin >> s;
	int n = s.size();
	vector<int> v(26);
	vector<vector<int>> f(26);
	for(int i = 0; i < n; i++){
		f[s[i] - 'a'].push_back(i);
		v[s[i] - 'a'] += 1;
	}


	int mn = n;
	for(int i = 0; i < 26; i++){
		if(v[i] == 0)
			continue;

		int count = 0;
		for(int j = 0; j < v[i]; j++){
			if(s[j] - 'a' != i)
				count += 1;
		}
		mn = min(mn, count);
		for(int j = v[i]; j < n; j++){
			if(s[j] - 'a' != i)
				count += 1;
			if(s[j - v[i]] - 'a' != i)
				count -= 1;

			mn = min(mn, count);
		}
	}

	cout << mn << "\n";
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