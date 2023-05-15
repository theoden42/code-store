
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
    int n;
    cin >> n;
    string s;
    cin >> s;

  	vector<int> successor(26, -1);

  	string ans = "";

  	auto check = [&](int val, int bro){
  		while(successor[val] != -1){
  			if(successor[val] == bro)return false;
  			val = successor[val];
  		}
  		return true;
  	};

    for(int k = 0; k < n; k++){
    	int val = s[k] - 'a';
    	int flag = 0;
    	int ind = -1;


    	for(int i = 0; i < 26; i++){
    		if(successor[i] == val){
    			flag = 1;
    			ans += (char)('a' + i);
    			break;
    		}
    	}

    	if(flag == 1)continue;

    	flag = 0;
    	for(int i = 0; i < 26; i++){
    		if(successor[i] == -1 && i != val && check(val, i)){
    			flag = 1;
    			successor[i] = val;
    			ans += (char)('a' + i);
    			break;
    		}
    	}
    	if(flag == 0){
    		for(int i = 0; i < 26; i++){
    			if(successor[i] == -1){
    				successor[i] = val;
    				ans += (char)('a' + i);
    			}
    		}
    	}

    }

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