

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

int isvowel(char c){
	return (c == 'a' || c == 'e');
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n + 1, INF);
    dp[n] = 0;// take 0 more characters;
    for(int i = n - 2; i >= 0; i--){
    	if(i < n - 2 && !isvowel(s[i]) && isvowel(s[i + 1]) && !isvowel(s[i + 2]) && dp[i + 3] != INF){
    		dp[i] = 3;
    	}
    	if(!isvowel(s[i]) && isvowel(s[i + 1]) && dp[i + 2] != INF){
    		dp[i] = 2;
    	}
    }

    // debug(dp);

    string ans = "";
    for(int i = 0; i < n; i++){
    	int ind = dp[i];
    	// debug(ind);
    	for(int j = i; j < i + ind; j++){
    		ans += s[j];
    	}
    	i = i + ind - 1;
    	ans += '.';
    }
    ans.pop_back();
    cout << ans << "\n";

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