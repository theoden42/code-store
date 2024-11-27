

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
	int n, m, x;
	cin >> n >> m >> x;
	vector<int> ball(n);
	ball[x - 1] = 1;
	for(int i = 0; i < m; i++){
		vector<int> nball(n);
		int d;
		cin >> d;
		char t;
		cin >> t;
		for(int j = 0; j < n; j++){
			if(ball[j]){
				if(t == '0'){
					int nw = (j + d) % n;
					nball[nw] = 1;
				} else if(t == '1'){
					int nw = (j - d % n + n) % n;
					nball[nw] = 1;
				} else {
					int nw1 = (j + d) % n;
					int nw2 = (j - d % n + n) % n;
					nball[nw1] = 1;
					nball[nw2] = 1;
				}
			}
		}
		// debug(ball);
		ball.assign(all(nball));
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		if(ball[i])
			count += 1;
	}
	cout << count << "\n";
	for(int i = 0; i < n; i++){
		if(ball[i]){
			cout << i + 1 << " ";
		}
	}
	cout << "\n";
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