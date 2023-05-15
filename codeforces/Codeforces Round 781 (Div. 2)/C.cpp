

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

	vector<int> parent(n);
	for(int i = 1; i <= n - 1; i++){
		int p;
		cin >> p;
		p--;
		parent[p]++;
	}

	vector<int> temp;

	for(int i = 0; i < n; i++){
		if(parent[i] != 0){
			temp.push_back(parent[i]);
		}
	}
	temp.push_back(1);
	sort(temp.rbegin(), temp.rend());

	debug(temp);

	int x = temp.size();
	int count = x;
	multiset<int> mst;

	for(int i = 0; i < x; i++){
		temp[i] = max(0, temp[i] - x + i);
		if(temp[i] != 0){
			mst.insert(temp[i]);
		}
	}


	int temp_count = 0;
	while(!mst.empty()){
		auto it = *(--mst.end());
		if(it <= temp_count)break;
		mst.erase(--mst.end());
		mst.insert(it - 1);
		temp_count++;
	}

	count += temp_count;
	cout << count << "\n";
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