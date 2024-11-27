

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


int is_prime(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}

	return true;
}

void solve() {
    int x, d;
    cin >> x >> d;
   	if(x % d != 0){
   		cout << "NO\n";
   		return;
   	}

   	int rem = x;
   	int count = 0;
   	while(rem % d == 0){
   		count++;
   		rem /= d;
   	}


   	if(count == 1){
   		cout << "NO\n";
   		return;
   	}
   	if(!is_prime(rem)){
   		cout << "YES\n";
   		return;
   	}
   	if(is_prime(d)){
   		cout << "NO\n";
   		return;
   	}

   	if(count > 3){
   		cout << "YES\n";
   		return;
   	}
   	else if(count == 2){
   		cout << "NO\n";
   		return;
   	}

   	for(int i = 2; i * i <= d; i++){
   		if(d % i != 0)continue;
   		int x = i;
   		int x2 = d / i;
   		if(x != rem || x2 != rem){
   			cout << "YES\n";
   			return;
   		}
   	}

   	cout << "NO\n";

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