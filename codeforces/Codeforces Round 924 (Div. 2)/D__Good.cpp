#include <bits/stdc++.h>
#include <debug.h>
using namespace std;
#define int long long
#define INF (int)9e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n, b, x; cin >> n >> b >> x;
    int mx = 0;
    vector <int> a(n);
    for (auto &x : a){
        cin >> x;
        mx = max(mx, x);
    }
    
    vector <int> f(mx + 1, 0);
    vector <int> d(mx + 2, 0);
    for (auto x : a){
        for (int i = 1; i <= x; i++){
            // there are i groups 
            int t1 = x / i;
            int t2 = (x + i - 1) / i;
            int n2 = x % i;
            int n1 = i - n2;
            
            int v = (n1 * (n1 - 1) / 2) * t1 * t1 + (n2 * (n2 - 1) / 2) * t2 * t2 + n1 * n2 * t1 *  t2;
            if (i == x) d[x + 1] += v;
            f[i] += v;
            // cout << i << " " << v << "\n";
        }
    }
    
    int sum = 0;
    for (int i = 1; i <= mx; i++){
        sum += d[i];
        f[i] += sum;
    }
    
    int ans = 0;
    for (int i = 1; i <= mx; i++) {
        debug(b * f[i] - (i - 1) * x);
        ans = max(ans, b * f[i] - (i - 1) * x);

    }
    
    cout << ans << "\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return 0;
}