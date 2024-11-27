

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

vector<vector<int>> p(400, vector<int>(1e5 + 5, 0));
vector<vector<int>> q(400, vector<int>(1e5 + 5, 0));

void solve() {
    int n, qr;
    cin >> n >> qr;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    for(int i = 1; i < 400; i++){   
        for(int j = 0; j < i; j++){
            int sum = 0;
            int sum2 = 0;
            int count = 1;
            for(int k = j; k < n; k += i){
                sum += (count * a[k]);
                sum2 += a[k];
                p[i][k + 1] = sum;
                q[i][k + 1] = sum2;
                count += 1;
            }
        }
    }


    for(int i = 1; i <= qr; i++){
    	int s, d, k;
    	cin >> s >> d >> k;
    	if(d < 400){
            int sum1 = p[d][s + d * (k - 1)] - (s - d < 0 ? 0 : p[d][s - d]);
            int sum2 = q[d][s + d * (k - 1)] - (s - d < 0 ? 0 : q[d][s - d]);
            int rem = (s - 1) % d;
            int num = ((s - 1) - rem) / d;
            int ans = sum1 - num * sum2;
            cout << ans << " \n"[i == qr];
    	} else {
            int sum = 0;
            int count = 1;
            for(int i = s - 1; i <= s - 1 + d * (k - 1); i += d){
                int x = count * a[i];
                sum += x;
                count += 1;
            }
            cout << sum << " \n"[i == qr];
    	}
    }


}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    p.assign(400, vector<int>(1e5 + 5, 0));
    q.assign(400, vector<int>(1e5 + 5, 0));
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}