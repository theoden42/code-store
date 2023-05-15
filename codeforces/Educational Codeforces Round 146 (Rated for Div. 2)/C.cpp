

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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<pair<int,int>> r(n);
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	r[i] = {x, i + 1};
    }
    sort(all(r));

    vector<int> l1, l2;
    int st1 = s1;
    int st2 = s2;
    for(int i = n - 1; i >= 0; i--){
    	if(st1 < st2){
    		l1.push_back(r[i].second);
    		st1 += s1;
    	}
    	else{
    		l2.push_back(r[i].second);
    		st2 += s2;
    	}
    }

    cout << l1.size() << " ";
    for(auto x: l1){
    	cout << x << " ";
    }
    cout << "\n";
    cout << l2.size() << " ";
    for(auto x: l2){
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