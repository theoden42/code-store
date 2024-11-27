

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
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	int s, c;
    	cin >> s >> c;
    	mp[s] = c;
    }

    multiset<pair<int,int>> mst;
    for(auto& it: mp) { 
    	mst.insert({it.first, it.second});
    }

    int count = 0;
    while(!mst.empty() && mst.begin()->second > 0ll) { 
    	auto val = mst.begin();
		int curr = (val->second) / 2ll;
		int sz = val->first;	
        if((val->second) & 1){
            count += 1;
        }

        mst.erase(mst.begin());
        if(curr == 0)
            continue;

        sz *= 2;
        if(mp.find(sz) == mp.end()) { 
            mp[sz] = curr;
            if(mp[sz] > 0) { 
                mst.insert({sz, mp[sz]});
            }
        } else {
            mst.erase(mst.find({sz, mp[sz]}));
            mp[sz] += curr;
            if(mp[sz] > 0) { 
                mst.insert({sz, mp[sz]});
            }
        }
    }

    cout << count << "\n";
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