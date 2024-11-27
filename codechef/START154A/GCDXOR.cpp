

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
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];

    int f = 1;
    for(int i = 1; i < n; i++){
    	if(a[i] != a[i - 1])
    		f = 0;
    }
    if(f){	
    	if(a[0] == k)	
    		cout << "0\n";
    	else 
    		cout << "1\n";
    	return;
    } 

    int count = 0;
    for(int i = 0; i < n; i++){
    	int j = i;
    	while(j < n && a[j] == a[i]){
    		j += 1;
    	}
    	if(a[i] != k)
    		count += 1;
    	i = j - 1;
    }

    if(count == 1){
    	cout << "1\n";
    	return;
    }

    f = 1;
    for(int i = 0; i < n; i++){
    	if(a[i] % k != 0){
    		f = 0;
    		break;
    	}
    }
    if(f){
    	cout << "1\n";
    	return;
    }	
    cout << 2 << "\n";	
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