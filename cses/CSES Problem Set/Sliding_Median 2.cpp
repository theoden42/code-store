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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}


	ordset<pair<int,int>> st;
	for(int i = 0; i < k; i++){
		st.insert({a[i], i});
	}

	ll sum = 0;
	ll sum2 = 0;
	for(int i = 0; i <= k / 2 - 1; i++){
		sum += st.find_by_order(i)->first;
	}
	for(int i = k / 2; i < n; i++){
		sum2 += st.find_by_order(i)->first;
	}



	for(int i = 0; i <= n - k; i++){

		if(k & 1){
			auto it = st.find_by_order(k / 2)->first;
			cout << it << " ";
		}
		else{
			auto it2 = st.find_by_order(k / 2 - 1)->first;
			cout << it2 << "\n";
		}

		if(i != n - k){
			st.erase(st.find({a[i], i}));
			st.insert({a[i + k], i + k});
		}

	}
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