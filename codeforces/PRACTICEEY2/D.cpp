

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

const int MAX_N = 1e7 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

long long c[MAX_N];
int ans[MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;

    for(int i = 1; i < MAX_N; i++){
    	for(int j = i; j < MAX_N; j += i){
    		c[j] += i;
    	}
    }


    for(int i = 1; i < MAX_N; i++){
    	if(c[i] < MAX_N && ans[c[i]] == 0){
    		ans[c[i]] = i;
    	}
    }

    for(int i = 1; i <= tc; i++){
	    int x;
	    cin >> x;
	    if(ans[x] == 0){
	    	cout << "-1\n";
	    } else {
	    	cout << ans[x] << "\n";
	    }
    }

}