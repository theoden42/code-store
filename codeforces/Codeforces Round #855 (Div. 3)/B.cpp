
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
    string s;
    cin >> s;
    map<int, int> mp;
    map<int,int> mp2;
    int ans = 0;

    for(int i = 0; i < n; i++){
    	if(s[i] >= 'a' && s[i] <= 'z'){
    		mp[s[i] - 'a']++;
    	}
    	else{
    		mp2[s[i] - 'A']++;
    	}
    }


    for(int i = 0; i < 26; i++){
    	int a = min(mp[i], mp2[i]);
    	int b = max(mp[i], mp2[i]);
    	ans += a;
    	int c = b - a;
    	int temp = min(k, c / 2);
    	ans += temp;
    	k -= temp;
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