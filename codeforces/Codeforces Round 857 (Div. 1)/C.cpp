
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
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    vector<pair<int,int>> b(n);


    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	int k;
    	cin >> k;
    	int mx = 0;
    	for(int j = 0; j < k; j++){
    		int x;
    		cin >> x;
            if(v[i].size() == 0 || v[i].back() < x)
    		v[i].push_back(x);
    		mx = max(mx, x);
    	}
    	b[i] = {mx, i};
    	mp[i] = mx;
    }

    vector<int> dp(n, 0);
    sort(all(b));


    dp[0] = v[b[0].second].size();

    for(int i = 1; i < n; i++){
        dp[i] = v[b[i].second].size();
    }


    vector<int> premax(n);
    premax[0] = 0;

    for(int i = 1; i < n; i++){
        int index = b[i].second;
        for(int j = v[index].size() - 1; j >= 0; j--){
            int val = v[index][j];

            int l = 0;
            int u = i - 1;
            int ind = -1;

            while(l <= u){
                int mid = l + (u - l) / 2;
                if(b[mid].first < val){
                    ind = mid;
                    l = mid + 1;
                }
                else{
                    u = mid - 1;
                }
            }
            if(ind == -1)continue;

            dp[i] = max(dp[i], dp[premax[ind]] + (int)v[index].size() - j);
        }   
        if(dp[i] > dp[premax[i - 1]]){
            premax[i] = i;
        }
        else{
            premax[i] = premax[i - 1];
        }
    }

    int mn = 0;
    for(int i = 0; i < n; ++i){
        mn = max(mn, dp[i]);
    }
    cout << mn << "\n";

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