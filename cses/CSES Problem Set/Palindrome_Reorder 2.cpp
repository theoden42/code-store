

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

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	string ans = "";	
	map<int,int> mp;


	for(int i = 0; i < n; i++){
		mp[s[i] - 'A']++;
	}

	debug(mp);


	int count = 0;
	for(int i = 0; i < 26; i++){
		if(mp[i] & 1){
			count++;
		}
		if(count > 1){
			cout << "NO SOLUTION\n";
			return;
		}
	}	

	char ch = '1';

	for(int i = 0; i < 26; i++){
		if(mp[i] & 1){
			for(int j = 1; j <= (mp[i] - 1) / 2; j++){
				ans += (char)('A' + i);
			}
			ch = (char)('A' + i);
		}
		else{
			for(int j = 1; j <= mp[i] / 2; j++){
				ans += (char)('A' + i);
			}
		}
	}

	string ans2 = ans;
	reverse(all(ans2));
	if(ch != '1'){
		ans += ch;
	}
	cout << ans + ans2 << "\n";
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