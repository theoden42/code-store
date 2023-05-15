
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    string s;
    cin >> s;
    int p;
    cin >> p;
    // cout << p << "\n";
    string ans = "";
    map<char,int> mp;
    string c;
    c = s;
    sort(s.rbegin(), s.rend());
    ll sum = 0;
    int n = s.length();
    for(int i = 0; i < n; i++){
    	sum += (int)(s[i] - 'a' + 1);
    }
    // cout << sum << "\n";
    for(int i = 0; i < n; i++){
    	if(sum <= p){
    		break;
    	}
    	mp[s[i]]++;
    	sum -= (int)(s[i] - 'a' + 1);
    	// cout << sum << "\n";
    }
    // for(auto& x : mp){
    // 	cout << x.first << " " << x.second << " \n";
    // }
    for(int i = 0; i < n; i++){
    	if(mp.find(c[i]) == mp.end() || mp[c[i]] == 0){
    		ans += c[i];
    	}
    	else{
    		mp[c[i]]--;
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