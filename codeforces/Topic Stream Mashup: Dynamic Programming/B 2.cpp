
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

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    long long ans = 0;
    map<char,int> mp;
    for(int i = 0; i < k; i++){
        char c;
        cin >> c;
        mp[c]++;
    }

    int lst = -1;
    for(int i = 0; i < n; i++){
        if(mp[s[i]] == 0){lst = -1;continue;}

        if(lst == -1)lst = i;
        ans += (0ll + i - lst + 1);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}