

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

int query(char dir, int k){
	cout << dir << " " << k << endl;	
	int x;
	cin >> x;
	return x;
}

void solve() {
    int n;
    cin >> n;
    map<int,int> mp;
    mp[n] = 1;

    int times = 0;
    int f = 0;

    for(int i = 2; i <= 1000; i++){
    	int val = query('+', 1);
    	times++;
    	if(mp.find(val) != mp.end()){
    		f = 1;
    		break;
    	}
    	mp[val] = i;
    }
    if(f){
    	cout << "! " << times << endl;
    	return;
    }

    int val = query('-', times);
    int count = 1;

    for(int i = 1; i <= 1000; i++){
    	int v = query('+', 1000);
    	if(mp.find(v) != mp.end()){
    		int ind = mp[v];
    		count += 1000 - ind;
    		break;
    	}
    	else{
    		count += 1000;
    	}
    }

    cout << "! " << count << endl;

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