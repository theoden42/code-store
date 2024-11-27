

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

int dp[2005][2005];

int better(int a, int b){
	if(a == 0 || b == 0)return 0;
	else if(a == 2 || b == 2)return 2;
	else return 1;
}


int check(int i, int j, string &s ,int ch);

int f(int i, int j, string& s){

	if(j < i)return 2;

	if(dp[i][j] != -1)return dp[i][j];	

	int a = check(i + 1, j, s, s[i - 1] - 'a');
	int b = check(i, j - 1, s, s[j - 1] - 'a');
	int val = better(a, b);

	return dp[i][j] = val;
}


int check(int i, int j, string &s, int ch){

	int x = f(i + 1, j, s);	
	int y = f(i, j - 1, s);	

	int val;

	if(x == 1 || y == 1){
		val = 1;
	}
	else if(x == 2 && s[i - 1] - 'a' < ch){
		val = 1;
	}
	else if(y == 2 && s[j - 1] - 'a' < ch){
		val = 1;
	}
	else if(x == 2 && s[i - 1] - 'a' == ch){
		val = 2;
	}
	else if(y == 2 && s[j - 1] - 'a' == ch){
		val = 2;
	}
	else{
		val = 0;
	}

	return val;
}



void solve() {
	string s;
	cin >> s;

	int n = s.size();

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = -1;
		}
	}

	int ans = f(1, n, s);
	if(ans == 0){
		cout << "Alice\n";
	}
	else if(ans == 1){
		cout << "Bob\n";
	}
	else{
		cout << "Draw\n";
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