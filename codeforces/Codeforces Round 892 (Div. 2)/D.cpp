

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

#define int long long

void solve() {
    int n;
    cin >> n;
    multiset<vector<int>> seg;

    for(int i = 0; i < n; i++){
    	int l, r, a, b;
    	cin >> l >> r >> a >> b;
    	seg.insert({l, r, b});

    }
    vector<vector<int>> v;

    while(!seg.empty()){
    	if((*seg.begin())[0] > (*seg.begin())[1]){
            seg.erase(seg.begin());
    		continue;
        }

    	if(v.empty() || (*seg.begin())[0] > v.back()[1]){
    		v.push_back({(*seg.begin())[0], (*seg.begin())[1], (*seg.begin())[2]});
            seg.erase(seg.begin());
    		continue;	
    	}

    	if(v.back()[2] >= (*seg.begin())[2]){
             auto temp = *seg.begin();
             seg.erase(seg.begin());
    		 temp[0] = v.back()[1] + 1;
             seg.insert(temp);
    	} else {
            // debug(v.back()[1], seg[i][0]);
    	    v.back()[1] = (*seg.begin())[0] - 1;
    	}
        // debug(v);
    }
    vector<vector<int>> temp;
    for(auto vv: v){
    	if(vv[0] > vv[1])
    		continue;
    	temp.push_back(vv);
    }
    v = temp;


    int q;
    cin >> q;
    vector<int> queries(q);
    for(int i = 0; i < q; i++){
        cin >> queries[i];
    }

    // if(n == 20){
    //     for(int i = 0; i < v.size(); i++){
    //         for(int j = 0; j < 3; j++){
    //             cout << v[i][j] << " ";
    //         }
    //         cout <<'\n';
    //     }

    //     for(auto in: queries){
    //         cout << in << " ";
    //     }
    //     cout << "\n";

    //     // return;

    // }

    int m = v.size();
    auto max_ind = [&](int pnt){
        int low = 0;
        int high = m - 1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(v[mid][0] <= pnt){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(ans == -1)
            return ans;

        if(v[ans][1] < pnt)
            return -1ll;
        else
            return ans;
    };

    vector<int> dp(m);
    dp[m - 1] = v[m - 1][2];
    for(int i = m - 2; i >= 0; i--){
        int pnt = v[i][2];
        int ind = max_ind(pnt);
        if(ind != -1){
            dp[i] = max(pnt, dp[ind]);
        }
        else {
            dp[i] = pnt;
        }
    }
    // if(n == 20){
    //     for(int i = 0; i < m; i++){
    //         cout << dp[i] << " ";
    //     }
    //     cout << "\n";

    // }

    for(auto in: queries){
        int mx = in;
        auto ind = max_ind(in);
        if(ind != -1){
            mx = max(mx, dp[ind]);
        }
        cout << mx << " ";
    }
    cout << "\n";

    // debug(queries);

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