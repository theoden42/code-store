

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

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
    	cin >> x[i];
    }

    map<int, vector<pair<int,int>>> mp;

    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n && x[j] == x[i]){
            j++;
        }
        mp[x[i]].push_back({i, j - 1});
        i = j - 1;
    }

    int mx = 1;
    int lb = 0;
    int rb = 0;
    int num = x[0];

    for(auto& it: mp){  

        int ones = 0;
        int spaces = 0;
        vector<pair<int,int>> ele = it.second;
        int leftindex = ele[0].first;

        for(int j = 0; j < ele.size(); j++){
            debug(ele[j]);
            ones += ele[j].second - ele[j].first + 1;
            int val = ones - spaces;
            if(val > mx){
                mx = val;
                lb = leftindex;
                rb = ele[j].second;
                num = it.first;
            }
            if(j != ele.size() - 1){
                spaces += (ele[j + 1].first - ele[j].second) - 1;
                if(spaces >= ones){
                    ones = 0;
                    spaces = 0;
                    leftindex = ele[j + 1].first;
                }
            }
        }
    }


    cout << num << " " << lb + 1 << " " << rb + 1 << "\n"; 

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