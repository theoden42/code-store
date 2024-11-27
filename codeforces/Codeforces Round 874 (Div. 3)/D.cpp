

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
    vector<int> p(n);
    for(int i = 0; i < n; i++){
    	cin >> p[i];
    }

    int ind = 0;
    int mxx = 0;
    for(int i = 1; i < n; i++){
    	if(p[i] > mxx){
    		mxx = p[i];
    		ind = i;
    	}
    }


    vector<int> mx;

    if(ind == n - 1){
    	for(int i = 0; i < n - 1; i++){
    		mx.push_back(p[i]);
    	}
    }
    else{
    	for(int i = ind - 1; i >= 0; i--){
    		mx.push_back(p[i]);
    	}
    }


    for(int i = ind - 1; i >= 0; i--){
    	vector<int> temp;
    	for(int j = ind - 1; j >= i; j--){
    		temp.push_back(p[j]);
    	}
    	for(int j = 0; j < i; j++){
    		temp.push_back(p[j]);
    	}

    	if(mx < temp){
    		mx = temp;
    	}
    }


    for(int i = ind; i < n; i++){
    	cout << p[i] << " ";
    }
    for(auto& x: mx){
    	cout << x << " ";
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