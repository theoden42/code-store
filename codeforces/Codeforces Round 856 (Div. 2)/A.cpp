
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
    vector<string> s;
    for(int i = 1; i <= 2 * n - 2; i++){
    	string t;
    	cin >> t;
    	if(t.size() == n - 1){
    		s.push_back(t);
    	}
    	else{
    		continue;
    	}
    }
    assert(s.size() == 2);

    string x  = s[0];
    string y = s[1];



    for(int i = 0; i < x.size(); i++){
    	if(x[i] == y[n - 2 - i]){
    		continue;
    	}
    	else{
    		cout << "No\n";
    		return;
    	}
    }
    cout << "Yes\n";


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