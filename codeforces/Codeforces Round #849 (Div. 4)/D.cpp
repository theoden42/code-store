
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
    string s;
    cin >> s;
    vector<multiset<int>> mst(26);
    for(int i = 0; i < n; i++){
    	mst[s[i] - 'a'].insert(i);
    }

    int mx = 0;
    for(int i = 0; i < n - 1; i++){
    	char c = s[i];
    	int count = 0;
    	for(int j = 0; j < 26; j++){
    		auto it1 = mst[j].lower_bound(i);
    		auto it2 = mst[j].upper_bound(i);
    		if(it2 != mst[j].begin()){
    			count++;
    		}
    		if(it2 != mst[j].end()){
    			count++;
    		}
    	}
    	mx = max(mx, count);
    }
    cout << mx << "\n";
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