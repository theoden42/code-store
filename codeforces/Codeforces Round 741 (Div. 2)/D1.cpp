

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
    string s;
    cin >> s;
    vector<int> p1(n + 1), p2(n + 1);
    for(int i = 1; i <= n; i++){
    	int val = ((s[i - 1] == '+') ? 1 : 0);
    	p1[i] = p1[i - 1];
    	p2[i] = p2[i - 1];
    	if(i & 1){
    		p1[i] += val;
    	} else {
    		p2[i] += val;
    	}
    }
    for(int i = 1; i <= q; i++){
    	int l, r;
    	cin >> l >> r;
        int sz = (r - l + 1);
        if(sz & 1){
            cout << 1 << "\n";
        } else {
            int v1 = p1[r] - p1[l - 1];
            int v2 = p2[r] - p2[l - 1];
            if(v1 == v2){
                cout << 0 << "\n";
            } else {
                cout << 2 << "\n";
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