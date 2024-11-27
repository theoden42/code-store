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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    for(int _ = 1; _ <= q; _++){
    	int l, r;
    	cin >> l >> r;
    	l--;
    	r--;
    	if(r - l + 1 >= 48){
    		cout << "YES\n";
    	} else {
            vector<int> temp;
            for(int i = l; i <= r; i++){
                temp.push_back(a[i]);
            }
            sort(all(temp));
            int l = -1, r = -1;
    		for(int i = 0; i < temp.size(); i++) if((int)temp.size() - i >= 3){
				if(temp[i] + temp[i + 1] > temp[i + 2]){
                    if(l == -1)l = i;
                    r = i;
				}
    		}
            int flag = 0;
    		for(int i = 0; i < (int)temp.size() - 5; i++){
                for(int j = i + 1; j <= i + 5; j++){
                    for(int k = j + 1; k <= i + 5; k++){
                        int v[4];
                        int ct = 0;
                        for(int l = i; l <= i + 5; l++){
                            if(l != i && l != j && l != k){
                                v[ct++] = temp[l];
                            }
                        }
                        if(temp[i] + temp[j] > temp[k] && v[0] + v[1] > v[2]){
                            flag = 1;
                        }
                    }
                }
    		}
            if(flag || (r - l >= 3)){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
    	}
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