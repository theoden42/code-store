

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
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if(xa >= xb){
    	cout << "Draw\n";
    	return;
    } 
    if(w <= 2){
    	int dist = xb - xa - 1;
    	if(dist & 1){
    		cout << "Bob\n";
    	} else {
    		cout << "Alice\n";
    	}
    	return;
    }

   	int dist = xb - xa - 1;
   	if(dist & 1){
   		if(ya == yb){
   			cout << "Bob\n";
   			return;
   		}
   		int bobmoves =  dist / 2;
   		if(ya < yb){
   			if(bobmoves >= yb - 2){
   				cout << "Bob\n";
   			} else {
   				cout << "Draw\n";
   			}
   		} else {
   			if(bobmoves >= w - yb - 1){
   				cout << "Bob\n";
   			} else {
   				cout << "Draw\n";
   			}
   		}
   	} else {
   		if(abs(ya - yb) <= 1){
   			cout << "Alice\n";
   			return;
   		}
   		int amoves = (dist) / 2;
   		if(yb < ya){
   			if(amoves >= ya - 2){
   				cout << "Alice\n";
   			} else {
   				cout << "Draw\n";
   			}
   		} else {
   			if(amoves >= w - 1 - ya){
   				cout << "Alice\n";
   			} else {
   				cout << "Draw\n";
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