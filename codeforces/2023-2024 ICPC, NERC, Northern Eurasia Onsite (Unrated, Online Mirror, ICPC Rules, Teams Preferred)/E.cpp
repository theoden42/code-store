

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

#define int long long

string get(int x,  int flag = 0){
	string temp = "";
	if(x == 0)
		return "";
	int val = x;
	if(x < 0){
		val = abs(x);

	}
	int count = 0;
	while(val != 0){
		int rem = val % 9;
		if(rem != 0){
			temp += (temp.empty()) ? "": "+";
			if(x < 0)
				temp += "0-";
			temp += to_string(rem);
			temp += (count != 0) ?  "*" : "";
			for(int i = 0; i < count; i++){
				temp += "9";
				if(i != count - 1)
					temp += "*";
			}
			if(flag)
				temp += "-0";
			if(x < 0)
				temp += "-0";
		}
		val /= 9;
		count += 1;
	}
	if(x < 0){
	}
	return temp;
}

void solve() {
    int p, q;
    cin >> p >> q;
    string st;
    if((p - q) & 1){
    	st += "12-4*4+5";
    	p -= 1;
    }
    int x = (p - q) / 2;
    int y = (p + q) / 2;
    string yst = get(y);
    string xst = get(x, 1);
    debug(x, y, xst, yst);
    if(!xst.empty()){
    	st += (st.empty()) ? "" : "+";
    	st += xst;
    }
    if(!yst.empty()){
    	st += (st.empty()) ? "" : "+";
    	st += yst;
    }

    cout << st << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //qcin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}