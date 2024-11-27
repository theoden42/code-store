

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

#define int long long

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

vector<int> freq(MAX_N);

int cacl_dist(vector<int>& a){
	if(a.size() < 4)
		return 0; 
	int n = a.size();
	int count = 0;
	gp_hash_table<int, int, chash> mp;
	for(int j = 1; j < n; j++){		
		for(int i = j - 1; i >= 0; i--){
			int val = a[i] ^ a[j];
			int cnt = freq[a[i]] * freq[a[j]];
			count += 8 * mp[val] * cnt;
			mp[val] += cnt;	
		}
	}
	return count;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		freq[a[i]] += 1;
	}
	vector<int> temp;
	set<int> st;
	for(int i = 0; i < n; i++){
		if(st.find(a[i]) == st.end()){
			temp.push_back(a[i]);
			st.insert(a[i]);
		}
	}

	int ans = cacl_dist(temp);

	int total = 0;
	for(auto& k: st){
		int v = freq[k];
		total += (v * (v - 1));
	}

	for(auto& k: st){
		int v = freq[k];
		int t = (v * (v - 1));

		ans += (t * (total - t));
	}
	cout << ans << "\n";
	for(int i = 0; i < n; i++){
		freq[a[i]] = 0;
	}
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}