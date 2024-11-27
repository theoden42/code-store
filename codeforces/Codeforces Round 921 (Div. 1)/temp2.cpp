

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

vector<string> findSchedules(int workHours, int dayHours, string pattern) {
	vector<string> ans;


	function<void(string, int, int)> dfs = [&](string pattern, int ind, int rem){
		if(ind == 7 && rem == 0){
			ans.push_back(pattern);
			return;
		} else if(ind == 7){
			return;
		}
		if(pattern[ind] != '?'){
			int v = pattern[ind] - '0';
			dfs(pattern, ind + 1, rem - v);
			return;
		}

		for(int i = 0; i <= dayHours; i++){
			pattern[ind] = (char)('0' + i);
			dfs(pattern, ind + 1, rem - i);
		}
	};

	dfs(pattern, 0, workHours);
	return ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
    	vector<string> val = findSchedules(56, 8, "???8???");
    	debug(val);
    }
}