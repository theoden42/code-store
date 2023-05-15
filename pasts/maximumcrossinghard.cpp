
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


template <typename T>
struct binary_indexed_tree{
    int N;
    vector<T> BIT;
    binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
    }
    void add(int i, T x){
        i++;
        while (i <= N){
            BIT[i] += x;
            i += i & -i;
        }
    }

    T sum(int i){
        T ans = 0;
        while (i > 0){
            ans += BIT[i];
            i -= i & -i;
        }
            return ans;
    }
    T sum(int L, int R){
        return sum(R) - sum(L);
    }
};

void solve() {
    ll n; cin >> n;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int mx = 2e5 + 2;
    ll ans = 0;
    binary_indexed_tree<int> bt(mx);
    for(int i = 0; i < n; i++){
    	ans += bt.sum(nums[i], mx);
    	bt.add(nums[i], 1);
    }
    cout << ans << "\n";
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