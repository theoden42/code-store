

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

int stockSpike(vector<int> prices, int k){
	int n = prices.size();
	vector<int> left(n), right(n);
	multiset<int> mst;

	for(int i = 0; i < n; i++){
		if(mst.size() == k && *mst.rbegin() < prices[i])
			left[i] = 1;
		if(mst.size() < k)
			mst.insert(prices[i]);
		else if(*mst.rbegin() > prices[i]){
			mst.erase(--mst.end());
			mst.insert(prices[i]);
		}
	}

	mst.clear();
	for(int i = n - 1; i >= 0; i--){
		if(mst.size() == k && *mst.rbegin() < prices[i])
			right[i] = 1;

		if(mst.size() < k)
			mst.insert(prices[i]);
		else if(*mst.rbegin() > prices[i]){
			mst.erase(--mst.end());
			mst.insert(prices[i]);
		}
	}

	int count = 0;
	for(int i = 0; i < n; i++){
		if(left[i] && right[i])
			count++;
	}
	return count;
}

void solve() {
    
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;

    cout << stockSpike({1, 3, 2, 5, 4}, 1) << "\n";
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}