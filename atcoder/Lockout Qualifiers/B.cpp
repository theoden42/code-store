
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
    vector<int> ele(4, 0);
    for(int i = 0; i < 4; i++){
    	ele[i] = s[i] - '0';
    }
    int flag = 0;
    for(int i = 0; i < 4; i++){
    	if(ele[i] != ele[0])flag = 1;
    }

    if(!flag){
    	cout << "Weak\n";
    	return;
    }

    flag = 1;


    for(int i = 1; i < 4; i++){
    	if(!(ele[i] == 0 && ele[i - 1] == 9)){
    		flag = 0;
    	}
    	else if(ele[i] != ele[i - 1] + 1){
    		flag = 0;
    	}
    }

    if(flag){
    	cout << "Weak\n";
    }
    else{
    	cout << "Strong\n";
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