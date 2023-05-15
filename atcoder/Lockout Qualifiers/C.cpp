
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < m; i++){
    	cin >> b[i];
    }
    multiset<int> mst;
    for(int i = 0; i < m; i++){
    	mst.insert(b[i]);
    }

    int mn = 1e9;
    for(int i = 0; i < n; i++){
    	auto it = mst.lower_bound(a[i]);
    	auto it2 = mst.upper_bound(a[i]);
    	if(it != mst.begin()){
    		it--;
    		mn = min(mn, abs(a[i] - *it));
    	}
    	if(it2 != mst.end()){
    		it2--;
    		mn = min(mn, abs(a[i] - *it2));
    	}
    }
    cout << mn << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}