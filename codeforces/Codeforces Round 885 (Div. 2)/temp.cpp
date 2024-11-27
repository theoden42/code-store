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

int f_cycles(int s, int k, int x){
	int ldigit = s % 10;
	int mv = cycles[ldigit][0] + x * cycles[ldigit][2];
	if(mv > k)
		return 0;

	int left = (k - mv) * new_s(s, x);
	return left;
}



void solve() {
	// debug(cycles);
    int s, k;
    cin >> s >> k;

    int mx = 0;
    int low = 0;
    int high = k;


    for(int i = 1; i <= 100; i++){
    	int mid = (low + high) / 2;
    	int val1 = f_cycles(s, k, mid);
    	int val2 = f_cycles(s, k, mid + 1);
    	// debug(mid, val1, val2);
    	// debug(low, high, val1, val2);
    	if(val2 != 0 && val2 >= val1){
    		low = mid;
    		mx = mid + 1;
    	}
    	else{
    		high = mid;
    	}
    }

    debug(mx, f_cycles(s, k, mx), f_cycles(s, k, mx + 1));

	if(mx == 0){
		int ans = s * k;
		int curr = s % 10;
		vector<int> vis(10, 0);
		int count = 0;
		int temp_s = s;
		while(!vis[curr]){
			vis[curr] = 1;
			int temp_ans = (k - count) * temp_s;
			ans = max(ans, temp_ans);
			temp_s += curr;
			curr *= 2;
			curr %= 10;
			count++;
		}
		cout << ans << "\n";

	}else{
		int ans = s * k;
		int curr = s % 10;
		vector<int> vis(10, 0);
		while(!vis[curr]){
			vis[curr] = 1;
			curr *= 2;
			curr %= 10;
		}
		vis.assign(10, 0);
		int count = mx * cycles[s % 10][2] + cycles[s % 10][0];
		int temp_s = s + mx * cycles[s % 10][3] + cycles[s % 10][1];
		while(!vis[curr] && count < k){
			vis[curr] = 1;
			int temp_ans = (k - count) * temp_s;
			debug(temp_ans);
			ans = max(ans, temp_ans);
			temp_s += curr;
			curr *= 2;
			curr %= 10;
			count++;
		}

		cout << ans << "\n";

	}


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