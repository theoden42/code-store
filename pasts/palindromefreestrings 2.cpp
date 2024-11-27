
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int checkpalindrome(string s){
	int n = s.size();
	for(int i = 0; i < n; i++){
		if(s[i] != s[n - 1 - i])return 0;
	}
	return 1;
}


int f(string& s, int pos, string prev, vector<map<string, int>>& dp){

	if(pos == s.size())return 1;


	if(dp[pos].find(s) != dp[pos].end()){
		return dp[pos][s];
	}


	if(pos < 4){
		if(s[pos] == '?'){
			string pos1 = prev + '1';
			string pos2 = prev + '0';

			dp[pos][prev] = (f(s, pos + 1, pos1, dp) | f(s, pos + 1, pos2, dp));


			return dp[pos][prev];
		}
		else{
			string pos1 = prev + s[pos];
			return dp[pos][prev] = (f(s, pos + 1, pos1, dp));
		}
	}

	if(pos == 4){
		if(s[pos] == '?'){
			string pos1 = prev + '1';
			string pos2 = prev + '0';

			int x = 0;
			if(!checkpalindrome(pos1)){
				x |= f(s, pos + 1, pos1, dp);
			}
			if(!checkpalindrome(pos2)){
				x |= f(s, pos + 1, pos2, dp);
			}

			return dp[pos][prev] = x;
		}
		else{
			string pos1 = prev + s[pos];
			if(!checkpalindrome(pos1)){
				return dp[pos][prev] = f(s, pos + 1, pos1, dp);
			}
			else{
				return dp[pos][prev] = 0;
			}
		}
	}



	if(s[pos] == '?'){
		//checkforfive and six letter palindromes
		string pos1 = prev + '1';
		string pos2 = prev + '0';

		int x = 0;
		if(!checkpalindrome(pos1.substr(1, 5)) && !checkpalindrome(pos1)){
			x |= f(s, pos + 1, pos1.substr(1, 5), dp);
		}
		if(!checkpalindrome(pos2) && !checkpalindrome(pos2.substr(1, 5))){
			x |= f(s, pos + 1, pos2.substr(1, 5), dp);
		}

		return dp[pos][prev] = x;
	}
	else{
		string pos1 = prev + s[pos];
		if(!checkpalindrome(pos1) && !checkpalindrome(pos1.substr(1, 5))){
			return dp[pos][prev] = f(s, pos + 1, pos1.substr(1, 5), dp);
		}
		else{
			return dp[pos][prev] = 0;
		}
	}
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<map<string, int>> dp(n);

    int ans = f(s, 0, "", dp);
    if(ans == 1){
    	cout << "POSSIBLE\n";
    }
    else{
    	cout << "IMPOSSIBLE\n";
    }


 }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}