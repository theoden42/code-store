
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
    vector<vector<int>> bmat(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
    	string s;
    	cin >> s;
    	for(int j = 0; j < n; j++){
    		bmat[i][j] = s[j] - '0';
    	}
    }
    vector<set<int>> sets(n);
    for(int i = 1; i <= n; i++){
    	sets[i - 1].insert(i);
    }

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(bmat[i][j] == 1){
    			for(auto& x: sets[i]){
    				sets[j].insert(x);
    			}
    		}
    	}
    }

    for(int i = 0; i < n; i++){
    	cout << sets[i].size() << " ";
    	for(auto& x: sets[i]){
    		cout << x << " ";
    	}
    	cout << "\n";
    }
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