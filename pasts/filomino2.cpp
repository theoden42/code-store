
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
    vector<int> ele(n);
    for(int i = 0; i < n; ++i){
    	cin >> ele[i];
    }

    vector<vector<int>> ans(n, vector<int>(n, -1));

    for(int i = 0; i < n; i++){
        int x = ele[i];
        int count = x;
        int r = i;  
        int c = i;
        while(count != 0 && r < n){
            debug(count, r, c);
            while(c >= 0 && ans[r][c] == -1 && count > 0){
                ans[r][c] = x;
                c--; 
                count--;
            }
            if(count != 0){
                c++;
                r++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i >= j){
                cout << ans[i][j] << " ";
            }
        }
        cout << "\n";
    }
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