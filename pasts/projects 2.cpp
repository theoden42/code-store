
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
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int,int>, int>> projects(n);

    for(int i = 0; i < n; i++){
    	int a, b, p;
    	cin >> a >> b >> p;
    	projects[i] = {{a, b}, p};
    }
    sort(all(projects));



    vector<int> dp(n + 1, 0);

    int day = 0;
    dp[n - 1] = projects[n - 1].second;

    debug(projects);


    auto findnext = [&](int val){
        int l = 0;
        int u = n - 1;
        int mx = -1; 
        while(l <= u){
            int mid = l + (u - l) / 2;
            if(projects[mid].first.first > val){
                mx = mid;
                u = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return mx;
    };


    for(int i = n - 2; i >= 0; i--){
        auto t = projects[i].first;
        int index = findnext(t.second);
        debug(index);
        if(index == -1){
            dp[i] = max(dp[i + 1], projects[i].second);
            continue;
        }
        dp[i] = max(dp[i + 1], dp[index] + projects[i].second);
    }

    cout << dp[0] << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}