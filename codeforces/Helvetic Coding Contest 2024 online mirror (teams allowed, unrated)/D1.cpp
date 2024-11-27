

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

int countdistinct(string& s){
	int n = s.size();
	unordered_map<string,int> mp;
	for(int i = 1; i <= s.size(); i++){
		for(int j = 0; j <= n - i; j++){
			mp[s.substr(j, i)] += 1;
		}
	}
	return mp.size();
}

void solve() {
	int n = 2;
	cin >> n;
	int q;
	if(n == 1){
		cout << "X" << endl;
		cin >> q;
		for(int i = 1; i <= q; i++){
			int x;
			cin >> x;
			cout << 1 << " " << 1 << endl;
		}
	} else if(n == 2) {
		cout << "OXOX" << " " << "OXX" << endl;
		cin >> q;
		vector<string> s = {"OXOX", "OXX"};
		for(int i = 1; i <= q; i++){
			int p;
			cin >> p;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					string temp = s[i] + s[j];
					if(countdistinct(temp) == p){
						cout << i + 1 << " " << j + 1 << endl;
					}
				}
			}
		}
	} else {
		cout << "OXOX" << " " << "X" << " " << "OXX" << endl;	
		vector<string> s = {"OXOX", "X", "OXX"};
		cin >> q;
		for(int i = 1; i <= q; i++){
			int p;
			cin >> p;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					string temp = s[i] + s[j];
					if(countdistinct(temp) == p){
						cout << i + 1 << " " << j + 1 << endl;
					}
				}
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