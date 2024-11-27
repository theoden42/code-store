

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
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	vector<int> c, d;
	c = a;
	d = b;
	sort(all(c));
	sort(all(d));
	if(c != d){
		cout << "No\n";
		return;
	}
	ordset<int> st;
	int ans1 = 0, ans2 = 0;
	for(int i = 0; i < n; i++){
		ans1 += st.size() - st.order_of_key(a[i]);
		st.insert(a[i]);
	}
	st.clear();
	for(int i = 0; i < n; i++){
		ans2 += st.size() - st.order_of_key(b[i]);
		st.insert(b[i]);
	}
	// debug(ans1, ans2);
	if((ans1 & 1) == (ans2 & 1)){
		cout << "Yes\n";
	} else {
		cout << "No\n";
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