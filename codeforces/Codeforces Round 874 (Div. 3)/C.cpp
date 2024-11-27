

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
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
    	cin >> a[i];
    }

    int f = 1;
    for(int i = 0; i < n; i++){
    	if(a[i] & 1)f = 0;
    }
    if(f){
    	cout << "YES\n";
    	return;
    }

    f = 1;
    for(int i = 0; i < n; i++){
    	if(!(a[i] & 1)) f = 0;
    }

    if(f){
    	cout << "YES\n";
    	return;
    }


    int mne = 1e9 + 5;
    int mno = 1e9 + 5;
    for(int i = 0; i < n; i++){
    	if(a[i] & 1){
    		mno = min(mno, a[i]);
    	}
    	else{
    		mne = min(mne, a[i]);
    	}
    }


    if(mne <= mno){
    	cout << "NO\n";
    	return;
    }
    cout << "YES\n";

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