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
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> mon(n);
    for(int i = 0; i < n; i++){
    	cin >> mon[i].second;
    }
    for(int j = 0; j < n; j++){
    	cin >> mon[j].first;
    }

   	multiset<pair<int,int>> mst;
   	for(int i = 0; i < n; i++){
   		mst.insert(mon[i]);
   	}
   	int dm = 0;
   	int att = k;

   	debug(mst);

   	while(att >= 0 && !mst.empty()){
   		dm += att;

   		while(!mst.empty()){
   			auto m = *mst.begin();
   			int h = m.second;
   			int p = m.first;
   			if(h <= dm){
   				mst.erase(mst.begin());
   			}
   			else{
   				att -= p;
   				m.second -= dm;
   				break;
   			}
   		}
   	}

   	if(mst.empty()){
   		cout << "YES\n";
   	}
   	else{
   		cout << "NO\n";
   	}
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}