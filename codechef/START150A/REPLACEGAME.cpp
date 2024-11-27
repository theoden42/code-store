

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
	string s, t;
	cin >> s >> t;
	if(s == t){
		cout << "0\n";
		return;
	}
	int j = 0;
	vector<int> vals;
	int flag = -1;
	for(int i = 0; i < n; i++){
		while(j < n && t[i] == t[j])
			j += 1;
		if(j - i >= k){
			flag = i;
			break;
		}		
		i = j - 1;
	}
	if(flag == -1){
		cout << "-1\n";
		return;
	}
	cout << (n - k) + 1 << "\n"; 
	for(int i = 0; i < flag; i++){
		cout << i + 1 << " " << t[i] << "\n";
	}
	for(int i = n - 1; i >= flag + k; i--){
		cout << i - k + 2 <<  " " << t[i] << "\n";
	}
	cout << flag + 1 << " " << t[flag] << "\n";
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