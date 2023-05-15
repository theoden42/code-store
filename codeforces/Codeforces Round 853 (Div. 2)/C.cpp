
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
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#define int long long 

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<pair<int,int>> pos(n + m + 1, {-1, -1});

    for(int i = 0; i < n; i++){
        pos[a[i]].first = 0;
    }

    vector<int> freq(n + m + 1, 0);

    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        int val = a[x - 1]; 
        freq[val] += i - pos[val].first;
        pos[val] = {pos[val].first, i};
        pos[y] = {i, -1};
        a[x - 1] = y;
    }


    for(int i = 0; i <= n + m; i++){
        if(pos[i].second == -1 && pos[i].first != -1){
            freq[i] += (m + 1 - pos[i].first);
        }
    }



    ll count = 1ll * n * m * (m + 1);
    debug(count);

    for(int i = 1; i <= n + m; i++){
        if(freq[i] == 0)continue;
        ll temp = 1ll * ((freq[i] - 1) * (freq[i])) / 2;
        count -= temp;
    }
    cout << count << "\n";
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