
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

int dp[1005][1 << 12];
int n, m;

void get_new_mask(int row,  int mask, int new_mask, vector<int>& n_masks){
    if(row == n + 1){
        n_masks.push_back(new_mask);
        return;
    }
    if(mask & (1 << row)){
        get_new_mask(row + 1, mask, new_mask, n_masks);
        return;
    }
    if(row != n){
        // we will check if the other one is not fixed as well than it can happend that we place 2 ones here or 2 zeros here
        if(!(mask & (1 << row)) && !(mask & (1 << (row + 1)))){
            get_new_mask(row + 2, mask, new_mask, n_masks);
            get_new_mask(row + 1, mask, new_mask + (1 << row), n_masks);
            return;
        }
    }
    // only possible way is that we have zero here and the next is a one so, we need to put a one here as well as this one is fixed as well 
    get_new_mask(row + 1, mask, new_mask + (1 << row), n_masks);
    return;
}

int solve(int col, int mask){
    if(col == m + 1){
    // last column to fill
        if(mask == 0){
            // no horizontal tiles are placed as they cannot be placed here: so
            return 1;
        }
        else return 0;
    }

    if(dp[col][mask] != -1)return dp[col][mask];

    vector<int> next_masks;

    get_new_mask(1, mask, 0, next_masks);

    int ans = 0;
    for(auto& n_masks: next_masks){
        ans = (ans + solve(col + 1, n_masks)) % MOD;
    }
    ans = ans % MOD;
    return dp[col][mask] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    memset(dp, -1, sizeof(dp));

    solve(1, 0);
    cout << dp[1][0] << "\n";
}