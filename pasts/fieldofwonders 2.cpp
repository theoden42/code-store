
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
    
    string s;
    cin >> s;

    int m;
    cin >> m;
    vector<string> ele(m);

    map<char,int> mp;

    for(int i = 0; i < n; i++){
    	if(s[i] != '*'){
    		mp[s[i]]++;
    	}
    }
    for(int i = 0; i < m; i++){
    	cin >> ele[i];
    }

    vector<string> matched;
    for(int i = 0; i < m; i++){
    	int flag = 0;
    	for(int j = 0; j < n; j++){
    		if(s[j] != '*'){
    			if(ele[i][j] != s[j]){
    				flag = 1;
    				break;
    			}
    		}
    		else{
    			if(mp.find(ele[i][j]) != mp.end()){
    				flag = 1;
    				break;
    			}
    		}
    	}
    	if(flag == 0){
    		matched.push_back(ele[i]);
    	}
    }


    int count = 0;
    debug(mp);

    for(int i = 0; i < 26; i++){
    	int c = 0;
    	char ch = (char)(i + 'a');
    	if(mp.find(ch) != mp.end()){
    		continue;
    	}
    	for(auto& x: matched){
    		int flag = 0;
    		for(int j = 0; j < (int)x.size(); j++){
    			if(x[j] == ch){ 
    				flag = 1;
                    debug(ch);
    				break;

    			}
    		}
    		if(flag == 1){
    			c++;
    		}
    	}
    	if(c == (int)matched.size()){
    		count++;
    	}
    }

    cout << count << "\n";	
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