

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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    debug(n, q, a);

    vector<vector<int>> query(q);
    vector<int> ans(q);

    for(int i = 0; i < q; i++){
    	int l, r;
    	cin >> l >> r;
    	query[i] = {l, r, i};
    }

    sort(all(query));

    debug(query);

    vector<int> prefix(n + 1);
    vector<int> sum(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
    	prefix[i] = prefix[i - 1] ^ a[i - 1];
    	sum[i] = sum[i - 1] + a[i - 1];
    }

    debug(prefix);

    map<int, multiset<int>> oddind;
    map<int, multiset<int>> evenind;

    int ind = n + 1;

    for(int i = q - 1; i >= 0; i--){
    	int l = query[i][0];
    	int r = query[i][1];
    	int x = query[i][2];

    	int len = r - l + 1;

    	for(int j = ind - 1; j >= l; j--){
    		if(j & 1){
    			oddind[prefix[j]].insert(j);
    		}else{
    			evenind[prefix[j]].insert(j);
    		}
    	}

    	ind = l;
    	if(sum[r] - sum[l - 1] == 0){
    		ans[x] = 0;
    	}
    	else if((prefix[r] ^ prefix[l - 1]) == 0){
    		if(len & 1){
    			ans[x] = 1;
    			continue;
    		}
    		int val = prefix[l - 1];

    		if((l & 1)){
    			if(!oddind[val].empty() && *(oddind[val].begin()) <= r - 1){

                    if(a[r - 1] == 0 || a[l - 1] == 0){
                        ans[x] = 1;
                    }
                    else{
                        ans[x] = 2;
                    }
    			}
   				else{
   					ans[x] = -1;
   				}
    		}
    		else{
    			if(!evenind[val].empty() && *(evenind[val].begin()) <= r - 1){
                   if(a[r - 1] == 0 || a[l - 1] == 0){
                    ans[x] = 1;
                   }
                   else{
                    ans[x] = 2;
                   }
    			}
    			else{
    				ans[x] = -1;
    			}
    		}

    	}
    	else{
    		ans[x] = -1;
    		continue;
    	}

    }

    for(int i = 0; i < q; i++){
    	cout << ans[i] << "\n";
    }

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