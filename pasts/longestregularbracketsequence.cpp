
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
    int n = s.size();
    int count = 0;	
    map<int,int> mp;
    int mx = 0;
    int x = 1;

    for(int i = 0; i < n; i++){
    	if(s[i] == '('){
    		count++;
    		if(mp.find(count) == mp.end()){
    			mp[count] = i;
    		}
    	}
    	else{
    		count--;
    		if(count < 0){
                debug(i);
    			mp.clear();
                count = 0;
    		}

    		if(mp.find(count + 1) != mp.end()){
    			int val = i - mp[count + 1] + 1;
    			if(val > mx){
                    debug(i, mp[count + 1]);
                    for(int j = mp[count + 1]; j <= i; j++){
                        cout << s[j];
                    }
                    cout << "\n";
    				mx = val;
    				x = 1;
    			}
    			else if(val == mx){
    				x++;
    			}
    		}
    	}
    }
    cout << mx << " " << x << "\n";
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