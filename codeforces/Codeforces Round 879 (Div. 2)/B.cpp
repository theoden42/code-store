

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
    string x, y;
    cin >> x >> y;
    if(x.size() < y.size()) swap(x, y);

    string temp = "";
   	for(int i = 1; i <= x.size() - y.size(); i++){
   		temp += '0';
   	}
   	temp += y;

   	int ind = x.size();
   	int count = 0;
   	for(int i = 0; i < x.size(); i++){
   		if(x[i] == temp[i])continue;
   		else{
   			count += abs(x[i] - temp[i]);	
   			ind = i;
   			break;
   		}
   	}

   	for(int j = ind + 1; j < x.size(); j++){
   		count += 9;
   	}

   	cout << count << "\n";

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