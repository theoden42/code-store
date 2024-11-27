
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
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    vector<int> vis(n, 0);
    vector<int> parent(n, -1);
    int count = 0;

    queue<int> q;
    q.push(0);

    while(!q.empty()){
    	int sr = q.front();
    	q.pop();
    	for(auto& x: g[sr]){
    		if(!vis[x]){
    			q.push(x);
    			parent[x] = sr;
    			vis[x] = 1;
    		}
    	}
    }

    vector<int> ans;

   	int p = parent[n - 1];
   	ans.push_back(n);
   	while(p != -1){
   		if(p == 0){
   			ans.push_back(p + 1);
   			break;
   		}
   		ans.push_back(p + 1);
   		p = parent[p];
   	}
  	if(ans[ans.size() - 1] != 1){
  		cout << "IMPOSSIBLE\n";
  	}
  	else{
  		cout << ans.size() << "\n";
  		for(int i = ans.size() - 1; i >= 0; i--){
  			cout << ans[i] << " ";
  		}
  	}

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}