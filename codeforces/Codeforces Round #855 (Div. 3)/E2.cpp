
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
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    string s1, s2;
    s1 = s;
    s2 = t;
    sort(all(s));
    sort(all(t));
    if(s != t){
    	cout << "NO\n";
    	return;
    }

    for(int i = 0; i < n; i++){
    	if(s1[i] == s2[i])continue;
    	if(i + k > n - 1 && i - k  < 0){
    		cout << "NO\n";
    		return;
    	}
    }
    cout << "YES\n";

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