

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

int query(vector<int>& a){
	cout << "? ";
	for(auto in: a){
		cout << in << " ";
	}
	cout << endl;
	int v;
	cin >> v;
	return v;
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> flag(n + 1, -1);
	flag[1] = 0;
	vector<int> choose(k);
	for(int i = 0; i < k; i++){
		choose[i] = i + 1;
	}

	int a = query(choose);
	choose[0] = n;
	int b = query(choose);	
	int c = (a ^ b);

	flag[n] = c;
	choose[0] = 1;

	for(int i = 2; i < n; i++){
		if(i <= k){
			choose[i - 1] = n;
			int val = query(choose);
			int x = (a ^ val ^ c);
			choose[i - 1] = i;
			flag[i] = x;
		} else{
			choose[0] = i;
			int val = query(choose);
			flag[i] = (val ^ a);
			choose[0] = 1;
		}
	}

	int countdif = 0;
	int firstval = 0;
	for(int i = 1; i <= k; i++){
		countdif += flag[i];
	}
	if(countdif & 1){
		firstval = 1 - a;
	} else{
		firstval = a;
	}

	vector<int> ans(n + 1);
	ans[1] = firstval;

	for(int i = 2; i <= n; i++){
		if(flag[i]){
			ans[i] = 1 - firstval;
		} else{
			ans[i] = firstval;
		}
	}

	cout << "! ";
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}