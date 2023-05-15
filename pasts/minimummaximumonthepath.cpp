
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


int check(int source, int dest, vector<vector<pair<int,int>>> g, int mx, int nofedges){

	if(source == dest)return 1; 

	int ans = 0;

	for(auto& x: g[source]){
		if(x.second <= mx){

		}
	}
}

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<pair<int,int>>> g(n + 1);
    for(int i = 0; i < m; i++){
    	int a, b, c;
    	cin >> a >> b >> c;
    	g[a].push_back({b, c});
    }

   	int l = 0;
   	int u = 1e9;
   	int mx = -1;

   	vector<int> vis(n + 1, 0);
   	while(l <= u){
   		int mid = l + (u - l) / 2;


   		if(check(1, n, g, d, mid)){
   			mx = max(mx, mid);
   			u = mid - 1;
   		}
   		else{
   			l = mid + 1;
   		}
   	}


   	if(mx == -1){
   		cout << "-1\n";
   	}
   	else{

   		for(int i = 1; i <= n; i++){
   			vis[i] = 0;
   		}
   		vector<int> path = getpath(1, n, g, d, mx);
   		cout << path.size() - 1 << " ";
   		for(auto& x: path){
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