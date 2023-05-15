

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

int fib[46];
	
void preprocess(){
	fib[0] = 1;
	fib[1] = 1;
	for(int i = 2; i < 46; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}
}

int f(int r, int x, int y){
	if(r == 0){
		return 1;
	}

	if(y > fib[r] || y <= fib[r + 1] - fib[r]){
		int x2 = (y > fib[r]) ? y - fib[r] : fib[r + 1] - y - fib[r] + 1;
		int y2 = x;
		return f(r - 1, x2, y2);
	}
	else{
		return 0;
	}

}

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	if(f(n, x, y)){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    preprocess();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}