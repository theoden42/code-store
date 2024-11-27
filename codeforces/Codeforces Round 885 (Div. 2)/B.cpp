

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
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    map<int,vector<int>> mp;

    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	mp[x].push_back(i);
    }

    int l = 0;
    int u = n;
    int ans = n;


    auto check = [&](int md)->bool{

    	for(auto it: mp){
    		vector<int> v = it.second;
    		int count = 0;
    		int flag = 1;
    		for(int i = 0; i < v.size(); i++){
    			int walk = ((i == 0) ? v[i] : v[i] - v[i - 1] - 1);

    			if(walk / 2 > md){
    				flag = 0;
    				break;
    			}
    			else if(walk <= md){
    				continue;
    			}
    			else{
    				count++;
    			}
    		}
    		int walk = (n - v[v.size() - 1] - 1);
    		if(walk / 2 > md){
    			flag = 0;
    		}
    		else if(walk > md){
    			count++;
    		}

    		if(flag && count <= 1){
    			// debug(md, it.first);
    			return true;
    		}
     	}
     	return false;
    };

    while(l <= u){
    	int mid = (l + u) / 2;
    	if(check(mid)){
			ans = mid;
			u = mid - 1;
    	}
    	else{
    		l = mid + 1;
    	}
    }

    cout << ans << "\n";
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