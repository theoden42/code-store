
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
    int x, n;
    cin >> x >> n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i){
    	cin >> v[i];
    }

    multiset<int> lights;
    multiset<vector<int>> mst;
    lights.insert(0);
    lights.insert(x);

    mst.insert({x, 0, x});

    int mx = x;

    for(int i = 0; i < n; i++){
    	int px = v[i];

		int it1 = *lights.upper_bound(px);
    	int it2 = *(--lights.lower_bound(px));


    	mst.erase(mst.find({it1 - it2, it2, it1}));
    	mst.insert({px - it2, it2, px});
    	mst.insert({it1 - px, px, it1});
    	lights.insert(px);
    	auto vn = *(--mst.end());
    	mx = vn[0];

    	cout << mx << " ";
    }

    cout << "\n";

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