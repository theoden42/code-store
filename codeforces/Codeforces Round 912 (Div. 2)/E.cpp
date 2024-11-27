

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
    int sx, sy;
    cin >> sx >> sy;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i];
    }

   	multiset<int> even;
   	multiset<int> odd;
   	for(int i = 0; i < n; i++){
   		int disp = abs(x[i] - sx) + abs(y[i] - sy);
   		if(!(disp & 1)){
   			even.insert(i + 1);
   		} else {
   			odd.insert(i + 1);
   		}
   	}


   	int secchoice = (n - 1) / 2;
   	if(even.size() <= secchoice){
   		cout << "Second" << endl;
   		for(int i = 0; i < n; i++){
   			if(i & 1){
   				if(!even.empty()){
   					auto it = even.begin();
   					int val = *it;
   					cout << val << endl;
   					even.erase(it);
   				} else {
   					auto it = odd.begin();
   					int val = *it;
   					cout << val << endl;
   					odd.erase(it);
   				}
   			} else {
   				int index;
   				cin >> index;
   				if(index == -1)
   					exit(1);
   				if(even.find(index) != even.end()){
   					even.erase(even.find(index));
   				} else{
   				 	odd.erase(odd.find(index));
   				}
   			}
   		}
   	} else {
   		cout << "First" << endl;
   		for(int i = 0; i < n; i++){
   			if(!(i & 1)){
   				if(!odd.empty()){
   					auto it = odd.begin();
   					int val = *it;
   					cout << val << endl;
   					odd.erase(it);
   				} else {
   					auto it = even.begin();
   					int val = *it;
   					cout << val << endl;
   					even.erase(it);
   				}
   			} else {
   				int index;
   				cin >> index;
   				if(index == -1)
   					exit(1);
   				if(even.find(index) != even.end()){
   					even.erase(even.find(index));
   				} else{
   				 	odd.erase(odd.find(index));
   				}
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