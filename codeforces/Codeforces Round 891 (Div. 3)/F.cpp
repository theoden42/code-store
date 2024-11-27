

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
		map<int,int> mp;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]]++;	
		}
		auto countpairs = [&](int v1, int v2){
			if(v1 != v2){
				v1 = mp[v1];
				v2 = mp[v2];
				return (v1 * v2);
			} else {
				v1 = mp[v1];
				return ((v1) * (v1 - 1)) / 2;
			}
		};
		int q;
		cin >> q;
		for(int i = 0; i < q; i++){
			int x, y;
			cin >> x >> y;
			int x2 = x * x;
			int d = x2 - 4 * y;
			// debug(d);
			if(d < 0){
				cout << 0 << " ";
				continue;
			}

			int low = 0;
			int high = 2e9;
			int sqd = -1;
			while(low <= high){
				int mid = (low + high) / 2;
				int midsq = mid * mid;
				if(midsq == d) {
					sqd = mid;
					break;
				} else if(midsq < d){
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}

			if(sqd == -1){
				cout << "0 ";
				continue;
			}
			
			set<vector<int>> st;
			int a1 = x + sqd;
			int a2 = x - sqd;
			int ans = 0;
			if(!(a1 & 1)){
				a1 /= 2;
				vector<int> v;
				v.push_back(a1);
				v.push_back(x - a1);
				sort(all(v));
				st.insert(v);
			}
			if(!(a2 & 1)){
				a2 /= 2;
				vector<int> v;
				v.push_back(a2);
				v.push_back(x - a2);
				sort(all(v));
				st.insert(v);
			}
			for(auto v: st){
				ans += countpairs(v[0], v[1]);
			}
			cout << ans << " ";
		}

		cout << "\n";

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