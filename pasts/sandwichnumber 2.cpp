
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

void solve() {
    string s;
    cin >> s;
    if(s.size() != 8){
    	cout << "No\n";
    	return;
    }
    int n = s.size();
    int a1 = s[0];
    int a2 = s[n - 1];

    if(a1 >= 'A' && a1 <= 'Z' && a2 >= 'A' && a2 <= 'Z'){
    	int number = 0;
    	for(int i = 1; i <= 6; i++){
    		if(s[i] <= '9' && s[i] >= '0'){
    			number = number * 10 + (s[i] - '0');
    		}
    		else{
    			cout << "No\n";
    			return;
    		}
    	}

    	if(number >= 100000 && number <= 999999){
    		cout << "Yes\n";
    	}
    	else{
    		cout << "No\n";
    	}
    }
	else{
		cout << "No\n";
	}
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}