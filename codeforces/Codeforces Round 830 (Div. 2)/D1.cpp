

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
	int q;
	cin >> q;
	map<int,int> mp;
	map<int,int> an;
	for(int i = 1; i <= q; i++){
		char ch;
		cin >> ch;
		if(ch == '+'){
			int x;
			cin >> x;
			mp[x] = 1;
			an[x] = 2 * x;
		}
		else{
			int k;
			cin >> k;
			if(an.find(k) == an.end()){
				cout << k << "\n";
			}
			else{
				int time = an[k] / k;
				while(true){	
					if(mp[k * time] == 1){
						an[k] = k * (time + 1);
						time++;
					}
					else{
						break;
					}
				}
				cout << an[k] << "\n";
			}
		}
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