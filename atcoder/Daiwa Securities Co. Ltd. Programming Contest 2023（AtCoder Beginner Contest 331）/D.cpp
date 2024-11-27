

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
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
    	cin >> s[i];
    }
    vector<vector<int>> an(n + 1, vector<int>(n + 1));
    vector<vector<int>> p(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		if(s[i - 1][j - 1] == 'B'){
    			an[i - 1][j - 1] = 1;
    		}
    	}
    }


    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + an[i - 1][j - 1];
    	}
    }
    // debug(p);

    auto f = [&](int a, int b){
        int comrows = (a + 1) / n;
        int comcols = (b + 1) / n;
        int prerow = (a + 1) % n;
        int precol = (b + 1) % n;

        // debug(comrows, comcols, prerow, precol);

        int temp = 0;
        temp += comrows * comcols * p[n][n];
        // debug(1, temp);
        temp += comrows * p[n][precol];
        temp += comcols * p[prerow][n];
        temp += p[prerow][precol];
        // debug(temp);
        return temp;

    };


    for(int i = 1; i <= q; i++){
    	int a, b, c, d;
    	cin >> a >> b >> c >> d;

        int ans = 0;
        ans += f(c, d);
        ans -= f(a - 1, d);
        ans -= f(c, b - 1);
        ans += f(a - 1, b - 1);

        cout << ans << "\n";
    }
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}