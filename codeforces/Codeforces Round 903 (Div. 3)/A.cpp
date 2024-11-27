

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

int issubstr(string& a, string& b){
	if(a.size() < b.size())
		return 0;
	for(int i = 0; i < a.size(); i++){
		if(a.substr(i, b.size()) == b){
			return 1;
		}
	}
	return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
   	string x, s;
   	cin >> x >> s;
   	if(issubstr(x, s)){
   		cout << 0 << "\n";
   		return;
   	}
   	for(int i = 1; i <= 5 || x.size() <= 4 * s.size(); i++){
   		x += x;
   		if(issubstr(x, s)){
   			cout << i << "\n";
   			return;
   		}
   	}

   	cout << "-1\n";

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