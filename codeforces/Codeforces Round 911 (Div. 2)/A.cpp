

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
	vector<int> lens;
	for(int i = 0; i < n; i++){
		if(s[i] != '.'){
			continue;
		} else {
			int j = i;
			while(j < n && s[j] == '.')
				j += 1;

			lens.push_back(j - i);
			i = j - 1;
		}
	}
	if(lens.empty()){
		cout << "0\n";
		return;
	}
	sort(all(lens));
	if(lens.back() > 2){
		cout << 2 << "\n";
	} else {
		int count = 0;
		for(auto l: lens){
			count += l;
		}
		cout << count << "\n";
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