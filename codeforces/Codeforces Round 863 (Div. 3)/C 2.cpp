

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
	vector<int> b(n - 1);
	for(int i = 0; i < n - 1; i++){
		cin >> b[i];
	}

	vector<int> a;
	a.push_back(b[0]);
	a.push_back(b[0]);
	for(int i = 1; i < n - 1; i++){
		int x = a.back();
		if(x > b[i]){
			a.pop_back();
			a.push_back(b[i]);
			a.push_back(b[i]);
		}
		else{
			a.push_back(b[i]);
		}
	}

	for(int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << endl;
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