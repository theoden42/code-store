

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

int check_vowel(char ch){
	return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');	
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> prefix(n + 1);
    for(int i = 1; i <= n; i++){
    	prefix[i] = prefix[i - 1] + (check_vowel(s[i - 1]));
    }

    int ans = 1;	

    if(prefix[n] % k != 0){
    	cout << "0\n";
    }
    else{
    	if(prefix[n] == 0){
    		cout << "0\n";
    		return;
    	}

    	int mx = prefix[n] / k;
    	vector<int> pos(mx + 1);

    	for(int i = 1; i <= n; i++){
    		if(prefix[i] % k == 0){
    			pos[prefix[i] / k]++;
    		}
    	}

    	int ans = 1;
    	for(int i = 1; i < mx; i++){
    		if(pos[i] == 0)break;
    		ans *= pos[i];
    		ans %= MOD;
    	}

    	cout << ans << "\n";
    }

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}