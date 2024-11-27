
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
    vector<vector<int>> g(n);

    vector<int> greater(n);

    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	if(v > u){
    		greater[u]++;
    	}
    	else{
    		greater[v]++;
    	}
    }
    int count = 0;

    for(int i = 0; i < n; i++){
    	if(greater[i] == 0)count++;
    }

    debug(greater);

	int q;
	cin >> q;



	for(int i = 0; i < q; i++){
		int t;
		cin >> t;
		if(t == 3){
			cout << count << "\n";
		}
		else if(t == 1){
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			if(u > v){
				if(greater[v] == 0)count--;
				greater[v]++;
			}
			else{
				if(greater[u] == 0)count--;
				greater[u]++;
			}
		}
		else{
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			if(u > v){
				greater[v]--;
				if(greater[v] == 0)count++;
			}
			else{	
				greater[u]--;
				if(greater[u] == 0)count++;
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}