

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


int mn = 0;

void recur(int i, int j, multiset<int>& mst, vector<int>& b){
	if(j - i < 3)return;

   	mst.erase(mst.find(b[i]));
	int x = *(--mst.end());
    mst.erase(--mst.end());
    int y = *(--mst.end());
    mst.erase(--mst.end());
    int z = *(--mst.end());
    mst.erase(--mst.end());

    mst.insert(x);
    mst.insert(y);
    mst.insert(z);
   	mst.insert(b[i]);


   	int a1 = x + y + z - (j - i - 1);

    // debug(x, y, z, a1, mst);
   	mst.erase(mst.find(b[j]));
	int x1 = *(--mst.end());
    mst.erase(--mst.end());
    int y1 = *(--mst.end());
    mst.erase(--mst.end());
    int z1 = *(--mst.end());
    mst.erase(--mst.end());

    mst.insert(x1);
    mst.insert(y1);
    mst.insert(z1);
   	mst.insert(b[j]);
   	int a2 = x1 + y1 + z1 - (j - i - 1);

   	if(a1 >= mn){
   		mn = max(mn, a1);
   		mst.erase(mst.find(b[i]));
   		recur(i + 1, j, mst, b);
   		mst.insert(b[i]);
   	}
   	if(a2 >= mn){
   		mn = max(mn, a2);
   		mst.erase(mst.find(b[j]));
   		recur(i, j - 1, mst, b);
   		mst.insert(b[j]);
   	}
   	else{
   		return;
   	}
}

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    multiset<int> mst;
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    	mst.insert(b[i]);
    }

    // debug(mst); 
    int i = 0;
    int j = n - 1;

    int x = *(--mst.end());
    mst.erase(--mst.end());
    int y = *(--mst.end());
    mst.erase(--mst.end());
    int z = *(--mst.end());
    mst.erase(--mst.end());

    // debug(x, y, z);

    mn = x + y + z - (j - i);
    mst.insert(x);
    mst.insert(y);
    mst.insert(z);

    recur(0, n - 1, mst, b);
    cout << mn << "\n";
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