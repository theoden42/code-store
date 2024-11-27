

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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), p1(n + 1), p2(n + 1), p3(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	p1[i] = p1[i - 1];
    	p2[i] = p2[i - 1];
    	p3[i] = p3[i - 1];
    	if(a[i] == 1)
    		p1[i]++;
    	else if(a[i] == 2)
    		p2[i]++;
    	else 
    		p3[i]++;
    }
    for(int i = 1; i <= q; i++){
    	int l, r;
    	cin >> l >> r;
    	int one = p1[r] - p1[l - 1];
    	int two = p2[r] - p2[l - 1];
    	int three = p3[r] - p3[l - 1];
    	vector<int> v = {one, two, three};
    	sort(all(v));
    	if((r - l + 1) & 1){
    		cout << "No\n";
    	} else {
    		if(v[0] + v[1] == v[2]){
    			cout << "Yes\n";
    		} else {
    			cout << "No\n";
    		}
    	}
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