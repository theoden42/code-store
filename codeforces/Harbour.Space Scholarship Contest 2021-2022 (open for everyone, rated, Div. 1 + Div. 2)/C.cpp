

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

	int calculate(string& x){
		int a = 0;
		int b = 0;
		for(int i = 0; i < 10; i++){
			if(i & 1){
				if(x[i] == '1')
					b++;
			}
			else{
				if(x[i] == '1')
					a++;
			}
			int remb = (10 - i) / 2;
			int rema = (9 - i) / 2;

			if(remb + b < a)
				return (i + 1);
			if(rema + a < b)
				return (i + 1);
		}
		return 10;

	}

	void get(int ind, string& x, string& nw, int& mn){
		if(ind == 10){
			int t = calculate(nw);
			mn = min(mn, t);
			return;
		}
		if(x[ind] != '?'){
			nw += x[ind];
			get(ind + 1, x, nw, mn);
			nw.pop_back();
		}
		else{
			nw += '1';
			get(ind + 1, x, nw, mn);
			nw.pop_back();
			nw += '0';
			get(ind + 1, x, nw, mn);
			nw.pop_back();
		}

	}


	void solve() {
	    string x;
	    cin >> x;
	    string nw = "";
	    int mn = 1e9;
	 	get(0, x, nw, mn);
	 	cout << mn << "\n";
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