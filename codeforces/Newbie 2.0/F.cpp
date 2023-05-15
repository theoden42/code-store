
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    map<int, vector<int>> x;
    map<int, vector<int>> y;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> mat[i][j];
    		x[mat[i][j]].push_back(i);
    		y[mat[i][j]].push_back(j);
    	}
    }

    ll count = 0;

    for(auto& temp: x){
    	ll sum = 0;
    	ll prefix = 0;
    	sort(all(temp.second));
    	int sz = temp.second.size();
    	for(int i = 0; i < sz; i++){
    		sum += (1ll * i * temp.second[i]) - prefix;
    		prefix += temp.second[i]; 
    	}
    	count += sum;
    }

    for(auto& temp: y){
    	ll sum = 0;
    	ll prefix = 0;
    	sort(all(temp.second));
    	int sz = temp.second.size();
    	for(int i = 0; i < sz; i++){
    		sum += (1ll * i * temp.second[i]) - prefix;
    		prefix += temp.second[i]; 
    	}
    	count += sum;
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