
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
    string ans = "";
    int count = k;
    vector<int> moves(n, 0);
    for(int i = 0; i < n; i++){
    	if(s[i] == '1' && k % 2 == 0){
    		ans += '1';
    	}
    	if(s[i] == '1' && k % 2 != 0){
    		if(count > 0){
    			moves[i]++;
    			ans += s[i];
    			count--;
    		}
    		else{
    			ans += '0';
    		}
    	}
    	if(s[i] == '0' && k % 2 == 0){
    		if(count > 0){
    			moves[i]++;
    			ans += '1';
    			count--;
    		}
    		else{
    			ans += '0';
    		}
    	}
    	if(s[i] == '0' && k % 2 != 0){
    		ans += '1';
    	}
    }
    debug(count);
    if(count > 0){
   		if(count % 2 == 0){
   			ans[ans.size() - 1] = ans[ans.size() - 1];
   		}
   		else{
   			if(ans[ans.size() - 1] == '0'){
   				ans[ans.size() - 1] = '1';
   			}
   			else{
   				ans[ans.size() - 1] = '0';
   			}
   		}
   		moves[n - 1] += count;
    }
    cout << ans << "\n";
    for(auto& x: moves){
    	cout << x << " ";
    }
    cout << "\n";
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