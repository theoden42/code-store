

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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    multiset<int> mst;
    multiset<int> mst2;


    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	mst.insert(a[i]);
    }
    for(int i = 0; i < m; i++){
    	cin >> b[i];
    	mst2.insert(b[i]);
    }


    int move = 0;	

    while(!mst.empty() && !mst2.empty()){
    	if(move == 0){
    		auto it = --mst.end();
    		auto it2 = mst2.begin();
    		int x = *it - *it2;
    		int y = *it2 - *it;
    		mst.erase(it);
    		mst2.erase(it2); 
    		if(x > 0){
    			mst.insert(x);
    		}
    		if(y > 0){
    			mst2.insert(y);
    		}
    	}
    	else{
    		auto it = mst.begin();
    		auto it2 = --mst2.end();

    		int x = *it - *it2;
    		int y = *it2 - *it;
    		mst.erase(it);
    		mst2.erase(it2); 
    		if(x > 0){
    			mst.insert(x);
    		}
    		if(y > 0){
    			mst2.insert(y);
    		}
    	}

    	move += 1;
    	move %= 2;
    }

    if(mst.empty() && mst2.empty()){
    	cout << "Draw\n";
    }
    else if(mst.empty()){
    	cout << "Tenzing\n";
    }
    else{
    	cout << "Tsondu\n";
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