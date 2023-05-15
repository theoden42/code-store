
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define int long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
        cin >> ele[i];
    }
    vector<pair<int,int>> min_cost(n);
    for(int i = 0; i < n; i++){
        min_cost[i] = {min(ele[i] + i + 1, ele[i] + n - i), i};
    }



    sort(all(min_cost));

    map<int,int> sorted_index;

    for(int i = 0; i < n; i++){
        sorted_index[min_cost[i].second] = i;
    }

    vector<int> prefix(n, 0);

    prefix[0] = min_cost[0].first;
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + min_cost[i].first;
    }


    auto func = [&](int start){
        int low = 0;
        int high = n - 1;
        int ind = -1;
        while(low <= high){
            int mid = (low + high) / 2; 
            int cost = ele[start] + start + 1 + ((sorted_index[start] <= mid) ? prefix[mid] - min_cost[sorted_index[start]].first : prefix[mid]);
            if(cost <= c){
                ind = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ind + 1;
    };

    int mn = 0;
    for(int i = 0; i < n; i++){
        if(ele[i] + i + 1 <= c){
            int t = func(i);
            t = t + ((t - 1 >= sorted_index[i]) ? 0 : 1);
            mn = max(mn, t);
        }
    }
    cout << mn << "\n";
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