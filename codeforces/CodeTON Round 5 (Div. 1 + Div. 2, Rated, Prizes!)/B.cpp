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
	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n), c(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}

	vector<int> na, nb, nc;


	set<int> st;
	int u = 0;
	for(int i = 0; i < n; i++){
		u = (u | a[i]);
		if(st.find(u) == st.end()){
			na.push_back(u);
			st.insert(u);
		}
	}

	st.clear();
	u = 0;
	for(int i = 0; i < n; i++){
		u = (u | b[i]);
		if(st.find(u) == st.end()){
			nb.push_back(u);
			st.insert(u);
		}
	}
	st.clear();
	u = 0;
	for(int i = 0; i < n; i++){
		u = (u | c[i]);
		if(st.find(u) == st.end()){
			nc.push_back(u);
			st.insert(u);
		}
	}

	int sza = na.size();
	int szb = nb.size();
	int szc = nc.size();
	vector<int> pa(sza + 1), pb(szb + 1), pc(szc + 1);

	for(int i = 1; i <= sza; i++){
		pa[i] = (pa[i - 1] | na[i - 1]);
	}

	for(int i = 1; i <= szb; i++){
		pb[i] = (pb[i - 1] | nb[i - 1]);
	}

	for(int i = 1; i <= szc; i++){
		pc[i] = (pc[i - 1] | nc[i - 1]);
	}
	
	
	for(int i = 0; i <= sza; i++){
		for(int j = 0; j <= szb; j++){
			for(int k = 0; k <= szc; k++){
				int vl = (pa[i] | pb[j] | pc[k]);
				if(vl == x){
					cout << "Yes\n";
					return;	
				}
			}
		}
	}

	cout << "No\n";


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