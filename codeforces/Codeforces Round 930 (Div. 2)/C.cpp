

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

int query(int a, int b, int c, int d){
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
	char ch;
	cin >> ch;
	if(ch == '=')
		return 0;
	else if(ch == '<')
		return -1;
	else 
		return 1;
}

void solve() {	
    int n;
    cin >> n;

    int mxind = 0;
    for(int i = 1; i < n; i++){
    	int v = query(mxind, mxind, i, i);
    	if(v == -1){
    		mxind = i;
    	}
    }

    vector<int> highind;
    highind.push_back(0);
    for(int i = 1; i < n; i++){
    	int v = query(mxind, highind.back(), mxind, i);
    	if(v == 0)
    		highind.push_back(i);
    	else if(v == -1){
    		highind.clear();
    		highind.push_back(i);
    	}
    }

    int ansind = highind.back();
    highind.pop_back();
    for(auto a: highind){
    	int v = query(ansind, ansind, a, a);
    	if(v == 1)
    		ansind = a;
    }

    cout << "! " << ansind << " " << mxind << endl;
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