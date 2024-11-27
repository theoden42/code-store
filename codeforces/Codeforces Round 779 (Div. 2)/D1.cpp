

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
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    vector<int> a(len);
    for(int i = 0; i < len; i++){
    	cin >> a[i];
    }
    int oxr = 0;
    for(int i = l; i <= r; i++){
    	oxr ^= i;	
    }
    int nxr = 0;
	for(int i = 0; i < len; i++){
		nxr ^= a[i];
	}

    if(len & 1){
    	int ans = (oxr ^ nxr);
    	cout << ans << "\n";
    }
    else{
        vector<int> oldbit(20, 0);
        for(int i = l; i <= r; i++){
            for(int j = 19; j >= 0; j--){
                if(i >> j & 1){
                    oldbit[j]++;
                }
            }
        }

        vector<int> newbit(20, 0);
        for(int i = 0; i < len; i++){
            for(int j = 19; j >= 0; j--){
                if(a[i] >> j & 1){
                    newbit[j]++;
                }
            }
        }

        // debug(oldbit, newbit);

        for(int i = 0; i < len; i++){
            int x = a[i];
            vector<int> changed(20, 0);
            for(int j = 19; j >= 0; j--){
                if(x >> j & 1){
                    changed[j] = len - oldbit[j];
                }
                else{
                    changed[j] = oldbit[j];
                }
            }   
            // debug(x, changed);
            if(changed == newbit){
                cout << x << "\n";
                return;
            }
        }
    }
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