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

#define int int64_t


vector<vector<int>> cycles;

void preprocess(){

	int linsize = 0;
	int linsum = 0;
	int cyclesize = 0;
	int cyclesum = 0;

	vector<int> vis(10, 0);

	for(int i = 0; i < 10; i++){
		vis.assign(10, 0);
		int val = i;
		int tot_sum = 0;
		int tot_count = 0;
		while(!vis[val]){
			vis[val] = 1;
			tot_sum += val;
			val = (2 * val) % 10;
			tot_count++;
		}
		int nsum = 0;
		int ncount = 0;
		int nval = i;
		while(val != nval){
			nsum += nval;
			nval = (2 * nval) % 10;
			ncount++;
		}
		linsum = nsum;
		linsize = ncount;
		cyclesize = tot_count - ncount;
		cyclesum = tot_sum - nsum;

		cycles.push_back({linsize, linsum, cyclesize, cyclesum});
	}
}

int new_s(int s, int x){
	//returns values of s after x complete cycles
	int ldigit = s % 10;
	int nsum = cycles[ldigit][1] + x * cycles[ldigit][3];
	return s + nsum;
}


void solve() {
    int s, k;
    cin >> s >> k;

    int mxans = s * k;

   	s += s % 10;
   	k--;
   	mxans = max(s * k, mxans);
   	if(s % 10 == 0){
   		cout << mxans << "\n";
   		return; 
   	}

    for(int i = 0; i < 4 && k > 0; i++){
    	int max_x = (20 * k - 4 * s) / 160;	
    	mxans = max(mxans, s * k);
    	for(int j = max(0ll, max_x - 2); j <= max_x + 2; j++){
    		int new_s = s + j * 20;
    		int new_k = k - 4 * j;
    		int new_val = new_s * new_k;
    		mxans = max(mxans, new_val);
    	}
    	s += s % 10;
    	k--;
    }

    cout << mxans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    preprocess();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}