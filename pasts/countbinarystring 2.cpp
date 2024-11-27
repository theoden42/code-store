
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
const ll MOD = 998244353;
const ll INF = 1e9;

void solve() {
    int n;
    vector<vector<int>> s(n, vector<int>());
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n - i; j++){
    		int x;
    		cin >> x;
    		s[i].push_back(x);
    	}
    }

    for(int i = 0; i < n; i++){
		int f = 0;
		for(auto& x: s[i]){
			if(x == 1){
				if(f == 0){
					continue;
				}
				else{
					cout << "0\n";
					return;
				}
			}
			else{
				if(f == 1){
					continue;
				}
				else{ f = 1;}
			}
		}
    }

    int lastone = -1;
    for(int i = 0; i < n; i++){
    	int ind0 = -1;
    	int ind1 = -1;
    	for(int j = 0; j < s[i].size(); j++){
    		if(s[j] == 1){
    			ind1 = j;
    		}
    	}
    }
	
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