
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
#define int long long 
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int q;
    cin >> q;
    multiset<int> mst;
    int count = 0;
    vector<int> pos(q, 0);


    vector<pair<int,int>> vp;
    vector<int> pushes(x);

    for(int i = 0; i < q; i++){
    	int t;
    	cin >> t;
    	if(t == 1){
    		int x;
    		cin >> x;
    		mst.insert(x);
    	}
    	else if(t == 2){
    		
    	}	
    	else{

    	}	
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}