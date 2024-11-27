

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


		auto check = [&](int val){

			vector<pair<int,int>> v;
			for(int i = 0; i < n; i++){
				int low = max(0ll, a[i] - val);
				int high = min((int)1e9, a[i] + val);
				v.push_back({low, high});	
			}	

			sort(all(v));
			multiset<pair<int,int>> st;

			for(int i = 0; i < v.size() && st.size() <= 3; i++){
				int f = 0;
				for(auto r: st){
					if(v[i].first > r.second || v[i].second < r.first)continue;
					else{
						int nl = max(v[i].first, r.first);
						int nr = min(v[i].second, r.second);

						st.erase(st.find({r}));
						st.insert({nl, nr});
						f = 1;
						break;
					}
				}
				if(!f){
					st.insert(v[i]);
				}
			}

			if(st.size() > 3)return false;
			else return true;

		};

		int l = 0;
		int u = 1e9;
		int mn = 1e9;
		while(l <= u){
			int mid = l + (u - l) / 2;
			if(check(mid)){
				mn = mid;
				u = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}


		cout << mn << "\n";


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