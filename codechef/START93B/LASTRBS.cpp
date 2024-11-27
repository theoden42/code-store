

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

int f(int ind, int curr, vector<int>& a, vector<vector<int>>& dp, string& ans){
	if(curr < 0)return false;

	if(ind == a.size()){
		return (curr == 0);
	}

	// debug(ind, curr);

	if(dp[ind][curr] != -1)return dp[ind][curr];	

	int cn = a[ind];

	if(f(ind + 1, curr + cn, a, dp, ans)){
		for(int i = 1; i <= cn; i++){
			ans += '(';
		}
		return dp[ind][curr] = true;
	}
	else if(f(ind + 1, curr - cn, a, dp, ans)){
		for(int i = 1; i <= cn; i++){
			ans += ')';
		}
		return dp[ind][curr] = true;
	}
	else{
		return dp[ind][curr] = false;
	}

}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;

    vector<int> a;
    for(int i = 0; i < n; i++){


    	int j = i;
    	int count = 0;
    	while(j < n && s[i] == s[j]){
    		count++;
    		j++;
    	}
    	a.push_back(count);
    	i = j - 1;
    }

    // debug(a);

    n = a.size();

    vector<vector<int>> dp(n + 1, vector<int> (s.size() + 1, -1));
    string ans = "";
    int check = f(0, 0, a, dp, ans);



    if(check){
    	cout << "YES\n";
    	reverse(all(ans));
    	cout << ans << "\n";
    }
    else{
    	cout << "NO\n";
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