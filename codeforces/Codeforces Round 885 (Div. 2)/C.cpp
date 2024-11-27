

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

	int step(int a, int b){

		if(a == 0)
			return 0;
		if(b == 0)
			return 1;

		if(a < b){
			int df = b - a;
			df /= (2 * a);
			b -= df * (2 * a);
			if(df == 0)
				return 1 + step(b, b - a);
			else
				return 3 * df + step(a, b);
		}
		else{
			int df = a - b;
			df /= (2 * b);
			a -= df * (2 * b);
			if(df == 0)
				return 1 + step(b, a - b);
			else
				return 3 * df + step(a, b);
		}

	}

	void solve() {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}

		set<int> st;
		for(int i = 0; i < n; i++){

			if(a[i] == 0 && b[i] == 0)
				continue;

			int cal = step(a[i], b[i]);
			st.insert(cal % 3);
		}
		if(st.size() <= 1){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
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