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

    debug(s);

    int level = 0;
    vector<int> ele(26, -1);
    vector<int> ind(26, -1);


    for(int i = 0; i < n; i++){


    	if(s[i] == '('){
    		level++;
    		continue;
    	}
    	else if(s[i] == ')'){
    		for(int j = 0; j <= 25 ; j++){
    			if(ele[j] != -1 && ind[j] >= level){
    				ele[j] = -1;
    				ind[j] = -1;
    			}
    		}
    		debug(i, ele, ind, level);
    		level--;
    		continue;
    	} 

    	int x = s[i] - 'a';
    	if(ele[x] != -1){
    		if(level >= ind[x]){
    			cout << "No\n";	
    			return;
    		}
    		ele[x] = 1;
    		ind[x] = level;
    	}
    	else{
    		ele[x] = 1;
    		ind[x] = level;
    	}

    	debug(ele, i, level);	
    }
    cout << "Yes\n";



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