

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
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int mx = *max_element(all(v));
	int mn = *min_element(all(v));
	int ind1 = 0, ind2 = 0;
	if(mx == mn){
		cout << "0\n";
		return;
	}
	for(int i = 0; i < n; i++){
		if(v[i] == mn){
			ind1 = i;
		}
		if(v[i] == mx){
			ind2 = i;
		}
	}
	if(ind2 < ind1){
		cout << "-1\n";
		return;
	}

	cout << n - 2 << "\n";
	while(v.size() > 2){
		vector<int> temp = {v[0], v[1], v[2]};
		sort(all(temp));
		vector<int> nw;
		int med = temp[(int)temp.size() / 2];
		int flag = 1;
		cout << 1 << " " << 3 << "\n";
		for(auto x: v){
			if(x == med && flag){
				flag = 0;
				continue;
			} else {
				nw.push_back(x);
			}
		}
		v = nw;
		debug(v);
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