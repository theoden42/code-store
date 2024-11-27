
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

auto cmp(pair<int,int> a, pair<int,int> b){
	if(a.first > b.first)return true;
	if(b.first > a.first)return false;

	if(a.second > b.second)return false;
	return true;
}

void solve() {
    int q;
    cin >> q;
    int ccust = 1;
    multiset<pair<int,int>> mst1;
    multiset<pair<int,int>> mst2;

    int c1 = 0, c2 = 0;

    for(int i = 1; i <= q; i++){
    	int t;
    	cin >> t;
    	if(t == 1){
    		int m;
    		cin >> m;
    		mst1.insert({ccust, m});
    		mst2.insert({-1 * m, ccust});
    		ccust++;
    	}	
    	else if(t == 2){
    		auto it = mst1.begin();
    		c1 += 1;
    		int a1 = it->first;
    		int a2 = it->second;
    		mst1.erase(it);
    		mst2.erase(mst2.find({ -1 * a2, a1}));
    		cout << a1 << " ";
    	}
    	else{
    		auto it = mst2.begin();
    		c2 += 1;
    		int a1 = it->first;
    		int a2 = it->second;
    		mst2.erase(it);
    		mst1.erase(mst1.find({a2, -1 * a1}));
    		cout << a2 << " ";
    	}
    }
    cout << endl;
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