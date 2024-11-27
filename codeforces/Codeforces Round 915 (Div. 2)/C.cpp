

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
	multiset<pair<int,int>> mst;
	for(int i = 0; i < n; i++){
		mst.insert({s[i] - 'a', -i});
	} 

	vector<int> indices;
	int curr = 0;
	while(!mst.empty()){
		auto [val, ind] = *(--mst.end());
		ind *= -1;
		indices.push_back(ind);
		while(curr <= ind){
			mst.erase(mst.find({s[curr] - 'a', -curr}));
			curr += 1;
		}
	}


	int i = 0;
	int j = indices.size() - 1;
	while(i <= j){
		swap(s[indices[i]], s[indices[j]]);
		i += 1;
		j -= 1;
	}

	for(int i = 1; i < n; i++){
		if(s[i] - 'a' < s[i - 1] - 'a'){
			cout << "-1\n";
			return;
		}
	}
	int ans = 0;
	for(int i = 0; i < indices.size(); i++){
		if(s[indices[i]] == s[indices.back()]){
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
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