

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

int mnvalue(vector<int>& v){
	int n = v.size();
	int ind = min_element(all(v)) - v.begin();
	int f = 1;
	for(int i = 0; i < n - 1; i++){
		if(v[(i + ind) % n] > (v[(i + ind + 1) % n])){
			f = 0;
			break;
		}
	}
	if(!f)
		return -1;
	else 
		return ind;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    int x1 = mnvalue(a);
    reverse(all(a));
    int x2 = mnvalue(a);

    if(x1 == -1 && x2 == -1){
    	cout << "-1\n";
    } else if(x1 == -1){
    	cout << 1 + x2 << "\n";
    } else if(x2 == -1){
    	cout << x1 << "\n";
    } else {
    	int ans = min(x1, 1 + x2);
    	cout << ans << "\n";
    }
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