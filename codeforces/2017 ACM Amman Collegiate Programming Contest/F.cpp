
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
    int n, k;
    cin >> n >> k;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    map<int,int> freq;
    for(int i = 0; i < n; ++i){
    	freq[ele[i]]++;
    }
    int count = 0;
    multiset<pair<int,int>> mst;
    int ans = 0;

    for(int i = 0; i < n; i++){
    	int x = ele[i];
    	int f = freq[x] - 1;
    	freq[x]--;

    	if(mst.find({f + 1, x}) != mst.end()){
    		mst.erase(mst.find({f + 1, x}));
    		mst.insert({f, x});
    		continue;
    	}
    	else{
    		if(count < k){
    			mst.insert({f, x});1
    			count++;
    			ans++;
    		}
    		else{
    			auto it = mst.begin();
    			mst.erase(it);
    			mst.insert({f, x});
    			ans++;
    		}
    	}
    }
    cout << ans << "\n";
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