
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
    int n;
    cin >> n;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    vector<pair<int,int>> ans;

    multiset<pair<int,int>> mst;
    for(int i = 0; i < n; i++){
    	mst.insert({ele[i], i});
    }

    for(int i = 0; i < n; i++){

    	auto it = *(mst.begin());
    	if(it.second == i){
    		mst.erase(mst.begin());
    		continue;
    	}
    	else{
    		ans.push_back({it.second, i});
    		ans.push_back({i, it.second});
    		ans.push_back({it.second, i});

    		mst.erase(mst.begin());
    		auto it2 = mst.find({ele[i], i});
    		mst.erase(it2);

    		mst.insert({ele[i], it.second});

    		swap(ele[i], ele[it.second]);
    	}
    }

    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++){
    	cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
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