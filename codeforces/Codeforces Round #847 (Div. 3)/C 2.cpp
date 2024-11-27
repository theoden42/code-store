
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
    vector<vector<int>> p(n, vector<int>(n - 1));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n - 1; j++){
    		cin >> p[i][j];
    	}
    }
    map<int,int> perm;
    for(int i = 0; i < n - 1; i++){
    	perm[p[0][i]]++;
    }

    int val = 0;
    for(int i = 1; i <= n; i++){
    	if(perm.find(i) == perm.end() || perm[i] == 0){
    		val = i;
    		break;
    	}
    }


    map<int,int> mp;
    for(int i = 1; i < n; i++){
    	for(int j = 0; j < n - 1; j++){
    		if(p[i][j] == val){
    			mp[j] += 1;
    		}
    	}
    }
    debug(mp);

    if(mp.size() > 1){
    	int mx = 0;
    	for(auto& x: mp){
    		mx = max(mx, x.first);
    	}
    	for(int i = 0; i < mx; i++){
    		cout << p[0][i] << " ";
    	}
    	cout << val << " ";

    	for(int i = mx; i < n - 1; i++){
    		cout << p[0][i] << " ";
    	}
    	cout << "\n";
    }
    else{
    	int ind = 0;
    	for(auto& x: mp){
    		ind = x.first;
    	}
    	if(ind == 0){
    		cout << val << " ";
    		for(int i = 0; i < n - 1; i++){
    			cout << p[0][i] << " ";
    		}
    		cout << "\n";
    	}
    	else{
    		for(int i = 0; i < n - 1; i++){
    			cout << p[0][i] << " ";
    		}
    		cout << val << "\n";
    	}

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