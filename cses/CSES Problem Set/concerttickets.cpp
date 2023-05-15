
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
    vector<int> h(m);
    vector<int> t(n);
    for(int i = 0; i < n; i++){
    	cin >> t[i];
    }
    for(int i = 0; i < m; i++){
    	cin >> h[i];
    }
    sort(all(t));

    vector<int> ans(m, -1);
    multiset<int> mst;
    for(int i = 0; i < n; i++){
    	mst.insert(t[i]);
    }

    for(int i = 0; i < m; i++){
    	int p = h[i];
    	auto it = mst.upper_bound(p);
    	if(it == mst.begin()){
    		ans[i] = -1;
    	}
    	else{
    		it--;
    		ans[i] = *it;
    		mst.erase(it);
    	}
    }

    for(auto& x: ans){
    	cout << x << "\n";
    }

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