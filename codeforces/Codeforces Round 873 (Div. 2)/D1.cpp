

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < n - 1; i++){
    	int mx = a[i];
    	vector<int> indices;
    	ordset<pair<int,int>> st;
    	indices.push_back(0);
    	st.insert({a[i], i});

		for(int j = i + 1; j < n; j++){
			st.insert({a[j], j});
			if(a[j] > mx){
				mx = a[j];
				indices.push_back(j - i);
			}	
			else{
				int ind = st.order_of_key({a[j], j});
				int del = (int)(indices.end() - lower_bound(all(indices), ind));
				int count = 0;
				while(count < del){
					indices.pop_back();
					count++;
				}
			}
			ans += max(0ll, (j - i - (int)indices.size()));
			debug(i, j, ans);
		}
    }

    cout << ans << "\n";
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