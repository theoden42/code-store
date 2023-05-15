
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
    int n, m;
    cin >> n >> m;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    m--;
    int count = 0;
    int sum = 0;
    int msum = 0;

    debug(ele, m, sum);

    multiset<pair<int,int>> mst;
    for(int i = 0; i <= m; i++){
    	msum += ele[i];
    }

    debug(msum);

    sum = msum;
    for(int i = m - 1; i >= 0; i--){
        sum = sum - ele[i + 1];
        mst.insert({ele[i + 1], i + 1});
        while(msum > sum){
            auto it = *(--mst.end());
            mst.erase(--mst.end());
            int ind = it.second;
            int val = it.first;
            msum -= 2 * val;
            ele[ind] *= -1;
            mst.insert({ele[ind], ind});
            count++;
        }
    }


    sum = msum;
    multiset<pair<int,int>> mst2;

    for(int i = m + 1; i < n; i++){
        mst2.insert({ele[i], i});
        sum += ele[i];
        while(msum > sum){
            auto it = (mst2.begin());
            int ind = it->second;
            int val = it->first;
            mst2.erase(it);
            sum -= 2 * val;
            ele[ind] = -1 * ele[ind];
            mst2.insert({ele[ind], ind});
            count++;
        }
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