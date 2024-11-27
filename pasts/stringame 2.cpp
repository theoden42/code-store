
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

bool check(string s, string t){
	// cout << s << " " << t << "\n";
	if(s.size() < t.size()){
		return false;
	}
	int k = 0;
	int i = 0;
	for(i = 0; i < t.size(); i++){
		while(s[k] != t[i] && k < s.size()){
			k++;
		}
		if(s[k] == t[i]){
			k++;
			continue;
		}
		if(k == s.size()){
			break;
		}
	}
	return i == t.size();
}

void solve() {
    string t, p;
    cin >> t >> p;
    int n = t.size();
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    int l = 0;
    int u = n - 1;
    int ans = 0;
    while(l <= u){
    	string s;
    	s = t;
    	string temp;
    	int mid = l + (u - l)/2;
    	// cout << mid << " ";
    	for(int i = 0; i < mid; i++){
    		s[ele[i] - 1] = '*';
    	}
    	for(int i = 0; i < n; i++){
    		if(s[i] != '*'){
    			temp += s[i];
    		}
    	}
    	// cout << mid << " " << temp << " " << p << "\n";
    	if(check(temp, p)){
    		ans = mid;
    		l = mid + 1;
    	}
    	else{
    		u = mid - 1;
    	}
    }
    cout << ans << "\n";
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