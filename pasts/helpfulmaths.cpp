
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
    vector<int> ans;
    for(int i = 0; i < s.size(); i++){
    	if(s[i] == '+')continue;
    	ans.push_back(s[i] - '0');
    }
    sort(all(ans));
    debug(ans);
    for(int i = 0; i < ans.size() - 1; i++){
    	cout << ans[i];
    	cout << "+";
    }
    cout << ans[ans.size() - 1];

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