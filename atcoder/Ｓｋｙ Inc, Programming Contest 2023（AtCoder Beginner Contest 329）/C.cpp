

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
	string s;
	cin >> s;
	vector<int> lens(26, 0);
	for(int i = 0; i < n; i++){
		int j = i;
		while(j < n && s[j] == s[i]){
			j += 1;
		}
		int l = j - i;
		lens[s[i] - 'a'] = max(lens[s[i] - 'a'], l);
		i = j - 1;
	}

	int ans = 0;
	for(int i = 0; i < 26; i++){
		ans += lens[i];
	}

	cout << ans << "\n";
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