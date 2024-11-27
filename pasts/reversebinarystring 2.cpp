
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int s1 = 0;
    int s2 = 0;
    int count = 0;
    for(int i = 1; i < n; i++){
    	if(s[i] == s[i - 1]){
    		if(s[i] == '0'){
    			if(s1 > 0){
    				s1--;
    			}
    			else{
    				s2++;
    				count++;
    			}
    		}
    		else{
    			if(s2 > 0){
    				s2--;
    			}
    			else{
    				s1++;
    				count++;
    			}
    		}
    	}
    }
    cout << count << "\n";
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