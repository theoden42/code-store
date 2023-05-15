
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
    string s, t;
    cin >> s >> t;
    if(s[0] == t[0]){
    	cout << "Yes\n";
    	cout << s[0] << "*" << "\n";
    	return;
    }

    if(s[s.size() - 1] == t[t.size() - 1]){
    	cout << "Yes\n";
    	cout << "*" << s[s.size() - 1] << "\n";
    	return;
    }

    for(int i = 0; i < s.size() - 1; i++){
    	string temp = s.substr(i, 2);
    	if(t.find(temp) != string::npos){
    		cout << "Yes\n";
    		cout << "*" << temp << "*\n";
    		return;
    	}
    }
    cout << "No\n";

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