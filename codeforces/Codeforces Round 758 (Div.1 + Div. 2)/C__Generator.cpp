

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
	int n = 5 + rng() % 5;
	cout << n << "\n";
	map<int,int> a, b;
	vector<int> av(n), bv(n);
	for(int i = 0; i < n; i++){
		int x = 5 + rng() % 10;
		while(a[x] != 0){
			x = 5 + rng() % 10;
		}
		av[i] = x;
		a[x] = 1;

		int y = 5 + rng() % 10;
		while(b[y] != 0){
			y = 5 + rng() % 10;
		}
		bv[i] = y;
		b[y] = 1;
	}

	shuffle(all(av), rng);
	shuffle(all(bv), rng);

	for(int i = 0; i < n; i++){
		cout << av[i] << " ";
	}
	cout << "\n";
	for(int i = 0; i < n; i++){
		cout << bv[i] << " ";
	}
	cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cout << "1\n";
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}