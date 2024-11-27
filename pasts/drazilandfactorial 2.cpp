
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
    vector<int> p;
    for(int i = 0; i < n; i++){
    	if(s[i] == '1' || s[i] == '0')
    		continue;
    	else{
    		if(s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9'){
    			if(s[i] == '4'){
    				p.push_back(3);
    				p.push_back(2);
    				p.push_back(2);
    			}
    			else if(s[i] == '6'){
    				p.push_back(3);
    				p.push_back(5);
    			}
                else if(s[i] == '9'){
                    p.push_back(3);
                    p.push_back(3);
                    p.push_back(7);
                    p.push_back(2);
                }
    			else{
    				p.push_back(2);
    				p.push_back(2);
    				p.push_back(2);
    				p.push_back(7);
    			}

    		}
    		else{
    			p.push_back(s[i] - '0');
    		}
    	}
    }
    sort(all(p));
    for(int i = p.size() - 1; i >= 0; i--){
    	cout << p[i];
    }
    cout << "\n";
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