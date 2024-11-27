

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
    int n;
    cin >> n;
    string s;
    cin >> s;
   	map<char,int> mp;
   	for(auto c: s){
   		mp[c] += 1;
   	}
   	if((abs(mp['N'] - mp['S']) & 1) || (abs(mp['E'] - mp['W']) & 1)){
   		cout << "NO\n";
   		return;
   	}
   	if((n == 2 && mp['N'] == 1 && mp['S'] == 1) 
   		|| (n == 2 && mp['E'] == 1 && mp['W'] == 1)){
   		cout << "NO\n";
   		return;
   	}

   	int nr = 0, sr = 0, er = 0, wr = 0;
   	nr = (mp['N'] + 1) / 2;
   	sr = (mp['S'] + 1) / 2;
   	er = mp['E'] / 2;
   	wr = mp['W'] / 2;


   	string ans = "";
   	for(int i = 0; i < n; i++){
   		if(s[i] == 'N' && nr > 0){
   			ans += "R";
   			nr -= 1;
   		} else if(s[i] == 'N'){
   			ans += "H";
   		}
   		if(s[i] == 'S' && sr > 0){
   			ans += "R";
   			sr -= 1;
   		} else if(s[i] == 'S'){
   			ans += "H";
   		} 
   		if(s[i] == 'E' && er > 0){
   			ans += "R";
   			er -= 1;
   		} else if(s[i] == 'E'){
   			ans += "H";
   		}
   		if(s[i] == 'W' && wr > 0){
   			ans += "R";
   			wr -= 1;
   		} else if(s[i] == 'W'){
   			ans += "H";
   		}
   	}

   	cout << ans << '\n';
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