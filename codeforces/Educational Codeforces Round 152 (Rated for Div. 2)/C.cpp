

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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;


    vector<int> leftmost(n, n), rightmost(n, -1);

    for(int i = 0; i < n; i++){
    	if(i != 0)
    		rightmost[i] = rightmost[i - 1];
    	if(s[i] == '0')
    		rightmost[i] = i;
    }

    for(int i = n - 1; i >= 0; i--){
    	if(i != n - 1){
    		leftmost[i] = leftmost[i + 1];
    	}
    	if(s[i] == '1')
    		leftmost[i] = i;
    }

    set<pair<int,int>> st;
    int flag = 0;
    for(int i = 0; i < m; i++){
    	int l, r;
    	cin >> l >> r;
    	l--;
    	r--;
    	// debug(l, r);
    	int left = leftmost[l];
    	int right = rightmost[r];
    	if(left > right || left > r || right < l){
    		flag = 1;
    		continue;
    	} else {
    		st.insert({left, right});
    	}
    }

    int ans = st.size() + flag;
    cout << ans << '\n';
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